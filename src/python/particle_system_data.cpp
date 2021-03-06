// Copyright (c) 2017 Doyub Kim
//
// I am making my contributions/submissions to this project solely in my
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#include "particle_system_data.h"
#include "pybind11_utils.h"

#include <jet/particle_system_data2.h>
#include <jet/particle_system_data3.h>

namespace py = pybind11;
using namespace jet;

void addParticleSystemData2(py::module& m) {
    py::class_<ParticleSystemData2, ParticleSystemData2Ptr, Serializable>(
        m, "ParticleSystemData2")
        .def(py::init<size_t>(),
             R"pbdoc(
             Constructs particle system data with given number of particles.
             )pbdoc",
             py::arg("numberOfParticles") = 0)
        .def_property_readonly("numberOfParticles",
                               &ParticleSystemData2::numberOfParticles)
        .def_property_readonly(
            "positions",
            [](ParticleSystemData2& instance) { return instance.positions(); })
        .def_property_readonly(
            "velocities",
            [](ParticleSystemData2& instance) { return instance.velocities(); })
        .def_property_readonly(
            "forces",
            [](ParticleSystemData2& instance) { return instance.forces(); })
        .def("scalarDataAt",
             [](ParticleSystemData2& instance, size_t idx) {
                 return instance.scalarDataAt(idx);
             })
        .def("vectorDataAt", [](ParticleSystemData2& instance, size_t idx) {
            return instance.vectorDataAt(idx);
        });
}

void addParticleSystemData3(py::module& m) {
    py::class_<ParticleSystemData3, ParticleSystemData3Ptr, Serializable>(
        m, "ParticleSystemData3")
        .def(py::init<size_t>(),
             R"pbdoc(
             Constructs particle system data with given number of particles.
             )pbdoc",
             py::arg("numberOfParticles") = 0)
        .def_property_readonly("numberOfParticles",
                               &ParticleSystemData3::numberOfParticles)
        .def_property_readonly(
            "positions",
            [](ParticleSystemData3& instance) { return instance.positions(); })
        .def_property_readonly(
            "velocities",
            [](ParticleSystemData3& instance) { return instance.velocities(); })
        .def_property_readonly(
            "forces",
            [](ParticleSystemData3& instance) { return instance.forces(); })
        .def("scalarDataAt",
             [](ParticleSystemData3& instance, size_t idx) {
                 return instance.scalarDataAt(idx);
             })
        .def("vectorDataAt", [](ParticleSystemData3& instance, size_t idx) {
            return instance.vectorDataAt(idx);
        });
}
