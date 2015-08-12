#include "AntApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"

template<>
InputParameters validParams<AntApp>()
{
  InputParameters params = validParams<MooseApp>();

  params.set<bool>("use_legacy_uo_initialization") = false;
  params.set<bool>("use_legacy_uo_aux_computation") = false;
  return params;
}

AntApp::AntApp(InputParameters parameters) :
    MooseApp(parameters)
{

  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  AntApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  AntApp::associateSyntax(_syntax, _action_factory);
}

AntApp::~AntApp()
{
}

extern "C" void AntApp__registerApps() { AntApp::registerApps(); }
void
AntApp::registerApps()
{
  registerApp(AntApp);
}

void
AntApp::registerObjects(Factory & factory)
{
}

void
AntApp::associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
}
