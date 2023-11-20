// File Line: 86
// RVA: 0x20DC40
UFG::Editor::SmartWarehouse *__fastcall UFG::Editor::SmartWarehouse::Instance()
{
  if ( !(_S26 & 1) )
  {
    _S26 |= 1u;
    UFG::qBaseTreeRB::qBaseTreeRB(&sSmartWarehouse.mInventories.mTree);
    atexit(UFG::Editor::SmartWarehouse::Instance_::_2_::_dynamic_atexit_destructor_for__sSmartWarehouse__);
  }
  return &sSmartWarehouse;
}

