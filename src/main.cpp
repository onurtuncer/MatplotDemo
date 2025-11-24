// ----------------------------------------------------------------------
// Copyright(c) 2025 Onur Tuncer, PhD, Istanbul Technical University
//
// SPDX - License - Identifier : MIT
// License - Filename : LICENSE
// ----------------------------------------------------------------------

#include <cmath>
#include <vector>
#include <matplot/matplot.h>


int main() {
    using namespace matplot;

    // --- Parameters ---
    const double R_earth = 6371.0;      // km, mean Earth radius
    const double h_orbit = 400.0;       // km, example orbit altitude
    const double R_traj = R_earth + h_orbit;

    // --- Generate Earth sphere mesh (lat/lon grid) ---
    auto lon = linspace(-pi, pi, 72);         // longitudes
    auto lat = linspace(-pi / 2, pi / 2, 36); // latitudes

    std::vector<std::vector<double>> X(lat.size(),
        std::vector<double>(lon.size()));
    std::vector<std::vector<double>> Y(lat.size(),
        std::vector<double>(lon.size()));
    std::vector<std::vector<double>> Z(lat.size(),
        std::vector<double>(lon.size()));

    for (size_t i = 0; i < lat.size(); ++i) {
        for (size_t j = 0; j < lon.size(); ++j) {
            double clat = std::cos(lat[i]);
            double slat = std::sin(lat[i]);
            double clon = std::cos(lon[j]);
            double slon = std::sin(lon[j]);

            X[i][j] = R_earth * clat * clon;
            Y[i][j] = R_earth * clat * slon;
            Z[i][j] = R_earth * slat;
        }
    }

    // --- Generate a dummy orbit in ECEF ---
    // Here: simple inclined circular orbit as an example
    const size_t N = 500;
    auto theta = linspace(0.0, 4.0 * pi, N);  // 2 full revolutions
    double inc = 51.6 * pi / 180.0;           // inclination (ISS-like)

    std::vector<double> x_traj(N), y_traj(N), z_traj(N);
    for (size_t k = 0; k < N; ++k) {
        double cth = std::cos(theta[k]);
        double sth = std::sin(theta[k]);

        // Simple inclined orbit in Earth-fixed frame
        x_traj[k] = R_traj * cth;
        y_traj[k] = R_traj * sth * std::cos(inc);
        z_traj[k] = R_traj * sth * std::sin(inc);
    }

    // --- Plotting with Matplot++ ---
    auto f = figure(true);
    auto ax = gca();
    hold(on);
    axis(equal);
    axis(tight);
    grid(on);
    ax->x_axis().label("x [km]");
    ax->y_axis().label("y [km]");
    ax->z_axis().label("z [km]");
    title("Orbit around Earth");

    // Earth surface
    auto earth = surf(X, Y, Z);
    earth->edge_color("none");
    colormap(palette::winter());   

    // Rocket trajectory
    auto traj = plot3(x_traj, y_traj, z_traj);
    traj->line_width(2.0);
    traj->color("red");

    // Optional: turn off axis box and make it nicer
    box(on);

    show();

    return 0;
}