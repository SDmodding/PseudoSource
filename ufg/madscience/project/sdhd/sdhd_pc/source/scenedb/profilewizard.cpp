// File Line: 184
// RVA: 0x15307E0
__int64 UFG::ProfileWizard::_dynamic_initializer_for__gProfileEntries__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::ProfileWizard::gProfileEntries.mTree);
  return atexit((int (__fastcall *)())UFG::ProfileWizard::_dynamic_atexit_destructor_for__gProfileEntries__);
}

// File Line: 185
// RVA: 0x1530880
__int64 UFG::ProfileWizard::_dynamic_initializer_for__gProfileSystems__()
{
  return atexit((int (__fastcall *)())UFG::ProfileWizard::_dynamic_atexit_destructor_for__gProfileSystems__);
}

// File Line: 868
// RVA: 0x15308A0
__int64 UFG::ProfileWizard::_dynamic_initializer_for__gRenderWizardEntries__()
{
  return atexit((int (__fastcall *)())UFG::ProfileWizard::_dynamic_atexit_destructor_for__gRenderWizardEntries__);
}

// File Line: 1210
// RVA: 0x4CA650
bool __fastcall UFG::ProfileWizard::IsProfiling()
{
  return UFG::ProfileWizard::sProfileWizard || UFG::ProfileWizard::sProfileGraph || UFG::ProfileWizard::sProfileIntoDB;
}

// File Line: 1426
// RVA: 0x1530810
__int64 UFG::ProfileWizard::_dynamic_initializer_for__gProfileGraph__()
{
  UFG::ProfileWizard::gProfileGraph.mHistoryPos = 0;
  UFG::ProfileWizard::gProfileGraph.mHistorySize = 256;
  UFG::ProfileWizard::gProfileGraph.mPosX = 100;
  UFG::ProfileWizard::gProfileGraph.mPosY = 700;
  UFG::ProfileWizard::gProfileGraph.mSizeX = 900;
  UFG::ProfileWizard::gProfileGraph.mSizeY = 200;
  return atexit((int (__fastcall *)())UFG::ProfileWizard::_dynamic_atexit_destructor_for__gProfileGraph__);
}

