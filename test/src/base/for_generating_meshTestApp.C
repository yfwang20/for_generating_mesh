//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "for_generating_meshTestApp.h"
#include "for_generating_meshApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
for_generating_meshTestApp::validParams()
{
  InputParameters params = for_generating_meshApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  return params;
}

for_generating_meshTestApp::for_generating_meshTestApp(InputParameters parameters) : MooseApp(parameters)
{
  for_generating_meshTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

for_generating_meshTestApp::~for_generating_meshTestApp() {}

void
for_generating_meshTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  for_generating_meshApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"for_generating_meshTestApp"});
    Registry::registerActionsTo(af, {"for_generating_meshTestApp"});
  }
}

void
for_generating_meshTestApp::registerApps()
{
  registerApp(for_generating_meshApp);
  registerApp(for_generating_meshTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
for_generating_meshTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  for_generating_meshTestApp::registerAll(f, af, s);
}
extern "C" void
for_generating_meshTestApp__registerApps()
{
  for_generating_meshTestApp::registerApps();
}
