#include "for_generating_meshApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
for_generating_meshApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  return params;
}

for_generating_meshApp::for_generating_meshApp(InputParameters parameters) : MooseApp(parameters)
{
  for_generating_meshApp::registerAll(_factory, _action_factory, _syntax);
}

for_generating_meshApp::~for_generating_meshApp() {}

void 
for_generating_meshApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAllObjects<for_generating_meshApp>(f, af, s);
  Registry::registerObjectsTo(f, {"for_generating_meshApp"});
  Registry::registerActionsTo(af, {"for_generating_meshApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
for_generating_meshApp::registerApps()
{
  registerApp(for_generating_meshApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
for_generating_meshApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  for_generating_meshApp::registerAll(f, af, s);
}
extern "C" void
for_generating_meshApp__registerApps()
{
  for_generating_meshApp::registerApps();
}
