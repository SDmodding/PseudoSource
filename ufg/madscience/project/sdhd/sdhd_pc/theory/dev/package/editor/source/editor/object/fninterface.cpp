// File Line: 21
// RVA: 0x146D960
__int64 UFG::Editor::_dynamic_initializer_for__gFnObjectInventory__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&stru_142040858);
  if ( !(_S26 & 1) )
  {
    _S26 |= 1u;
    UFG::qBaseTreeRB::qBaseTreeRB(&sSmartWarehouse.mInventories.mTree);
    atexit(UFG::Editor::SmartWarehouse::Instance_::_2_::_dynamic_atexit_destructor_for__sSmartWarehouse__);
  }
  UFG::qBaseTreeRB::Add(&sSmartWarehouse.mInventories.mTree, &UFG::Editor::gFnObjectInventory.mNode);
  return atexit(UFG::Editor::_dynamic_atexit_destructor_for__gFnObjectInventory__);
}

// File Line: 73
// RVA: 0x20C260
UFG::Editor::FnModifier *__fastcall UFG::Editor::FnObject::GetModifier(UFG::Editor::FnObject *this, UFG::qSymbol *symbol)
{
  unsigned int v2; // eax
  unsigned int v3; // er9
  unsigned int v4; // edx
  UFG::Editor::FnModifier **v5; // rcx
  UFG::Editor::FnModifier *v6; // r8
  UFG::Editor::FnModifier *result; // rax
  unsigned int v8; // er8
  UFG::Editor::FnModifier **v9; // rcx

  v2 = 0;
  if ( symbol->mUID == -1 )
  {
    v3 = this->mFnModifiers.size;
    v4 = 0;
    if ( v3 )
    {
      v5 = this->mFnModifiers.p;
      while ( 1 )
      {
        v6 = *v5;
        if ( (*v5)->mTypeID == 1864359155 )
          break;
        ++v4;
        ++v5;
        if ( v4 >= v3 )
          goto LABEL_6;
      }
    }
    else
    {
LABEL_6:
      v6 = 0i64;
    }
    result = v6;
  }
  else
  {
    v8 = this->mFnModifiers.size;
    if ( v8 )
    {
      v9 = this->mFnModifiers.p;
      while ( (*v9)->mSymbol.mUID != symbol->mUID )
      {
        ++v2;
        ++v9;
        if ( v2 >= v8 )
          goto LABEL_12;
      }
      result = *v9;
    }
    else
    {
LABEL_12:
      result = 0i64;
    }
  }
  return result;
}

