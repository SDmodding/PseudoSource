// File Line: 33
// RVA: 0x146E640
__int64 UFG::Editor::FreezeManager::_dynamic_initializer_for__mFrozenObjects__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::Editor::FreezeManager::mFrozenObjects.mTree);
  return atexit(UFG::Editor::FreezeManager::_dynamic_atexit_destructor_for__mFrozenObjects__);
}

