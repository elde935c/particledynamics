// #define CPPHTTPLIB_OPENSSL_SUPPORT
#include "../cpp-httplib/httplib.h"
#include "Simulation.hpp"
#include "SimulationBase.hpp"
// #include "../json/include/nlohmann/json.hpp"
#include <nlohmann/json.hpp>


using json = nlohmann::json;

SimulationBase sim;

SimulationBase getSimulation(const std::string &precision) {
    if (precision == "float") {
        return Simulation<float>(0.0f);
    }
    else if (precision == "double") {
        return Simulation<double>(0.0);
    }
    else {
        throw std::invalid_argument("Invalid precision");
    }
}


void create_simulation(const httplib::Request &req, httplib::Response &res) {
    try {
        json data = json::parse(req.body);
        sim = getSimulation(data["precision"]);
    } catch (const std::exception &e) {
        res.status = 400;
        res.set_content("{\"error\": \"Invalid JSON\"}", "application/json");
    }
}


// todo make functions for all different constructors
void add_particle(const httplib::Request &req, httplib::Response &res) {
    try {
        json data = json::parse(req.body);
        if (data["type"] == "Particle") {
            sim.addParticle(new Particle<float>());
        }
        else if (data["type"] == "Electron") {
            sim.addParticle(new Electron<float>());
        }
        else {
            throw std::invalid_argument("Invalid particle type");
        }
    } catch (const std::exception &e) {
        res.status = 400;
        res.set_content("{\"error\": \"Invalid JSON\"}", "application/json");
    }
}


int main () {
    httplib::Server svr;

    svr.Post("/create_simulation", create_simulation);

    svr.listen("localhost", 8080);

    return 0;
}