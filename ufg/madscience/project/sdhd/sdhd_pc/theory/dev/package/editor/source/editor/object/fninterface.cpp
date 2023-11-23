// File Line: 21
// RVA: 0x146D960
__int64 UFG::Editor::_dynamic_initializer_for__gFnObjectInventory__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&stru_142040858);
  if ( (_S26 & 1) == 0 )
  {
    _S26 |= 1u;
    UFG::qBaseTreeRB::qBaseTreeRB(&sSmartWarehouse.mInventories.mTree);
    atexit((int (__fastcall *)())UFG::Editor::SmartWarehouse::Instance_::_2_::_dynamic_atexit_destructor_for__sSmartWarehouse__);
  }
  UFG::qBaseTreeRB::Add(&sSmartWarehouse.mInventories.mTree, &UFG::Editor::gFnObjectInventory.mNode);
  return atexit((int (__fastcall *)())UFG::Editor::_dynamic_atexit_destructor_for__gFnObjectInventory__);
}

// File Line: 73
// RVA: 0x20C260
UFG::Editor::FnModifier *__fastcall UFG::Editor::FnObject::GetModifier(
        UFG::Editor::FnObject *this,
        UFG::qSymbol *symbol)
{
  int v2; // eax
  unsigned int size; // r9d
  int v4; // edx
  UFG::Editor::FnModifier **i; // rcx
  UFG::Editor::FnModifier *v6; // r8
  unsigned int v8; // r8d
  UFG::Editor::FnModifier **j; // rcx

  v2 = 0;
  if ( symbol->mUID == -1 )
  {
    size = this->mFnModifiers.size;
    v4 = 0;
    if ( !size )
      return 0i64;
    for ( i = this->mFnModifiers.p; ; ++i )
    {
      v6 = *i;
      if ( (*i)->mTypeID == 1864359155 )
        break;
      if ( ++v4 >= size )
        return 0i64;
    }
    return v6;
  }
  else
  {
    v8 = this->mFnModifiers.size;
    if ( v8 )
    {
      for ( j = this->mFnModifiers.p; (*j)->mSymbol.mUID != symbol->mUID; ++j )
      {
        if ( ++v2 >= v8 )
          return 0i64;
      }
      return *j;
    }
    else
    {
      return 0i64;
    }
  }
}

