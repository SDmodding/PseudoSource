// File Line: 4
// RVA: 0x5B7F80
void __fastcall InitEnums(UFG::qTreeRB<UEL::EnumBindingEntry,UEL::EnumBindingEntry,1> *EnumBindings)
{
  UFG::allocator::free_link *v2; // rdx
  unsigned int mUID; // eax
  int v4; // r8d
  signed int size; // esi
  int v6; // r8d
  UFG::qArray<char *,0> *p_m_enumName; // rax
  char **p; // rdi
  UFG::allocator::free_link *v9; // rdx
  int v10; // eax
  UFG::qSymbol result; // [rsp+50h] [rbp+8h] BYREF
  UFG::allocator::free_link *v12; // [rsp+58h] [rbp+10h] BYREF
  UFG::allocator::free_link *v13; // [rsp+60h] [rbp+18h]

  UFG::qSymbol::create_from_string(&result, "eTargetType");
  v2 = UFG::qMalloc(0x30ui64, UFG::gGlobalNewName, 0i64);
  v12 = v2;
  if ( v2 )
  {
    mUID = result.mUID;
    v2->mNext = 0i64;
    v2[1].mNext = 0i64;
    v2[2].mNext = 0i64;
    LODWORD(v2[3].mNext) = mUID;
    LODWORD(v2[4].mNext) = mUID;
    HIDWORD(v2[4].mNext) = 91;
    v2[5].mNext = (UFG::allocator::free_link *)UFG::TargetTypeEnumNames;
  }
  else
  {
    v2 = 0i64;
  }
  UFG::qBaseTreeRB::Add(&EnumBindings->mTree, (UFG::qBaseNodeRB *)v2);
  UFG::qSymbol::create_from_string((UFG::qSymbol *)&v12, "eActionRequest");
  UFG::qSymbol::create_from_string(&result, "ActionRequestEnum");
  v4 = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    while ( gActionRequestEnum.m_enumLists.p[v4]->m_listName.mUID != result.mUID )
    {
      if ( ++v4 >= gActionRequestEnum.m_enumLists.size )
        return;
    }
    size = gActionRequestEnum.m_enumLists.p[v4]->m_enumName.size;
    if ( size > 0 )
    {
      v6 = 0;
      while ( gActionRequestEnum.m_enumLists.p[v6]->m_listName.mUID != result.mUID )
      {
        if ( ++v6 >= gActionRequestEnum.m_enumLists.size )
        {
          p_m_enumName = 0i64;
          goto LABEL_14;
        }
      }
      p_m_enumName = &gActionRequestEnum.m_enumLists.p[v6]->m_enumName;
LABEL_14:
      p = p_m_enumName->p;
      v9 = UFG::qMalloc(0x30ui64, UFG::gGlobalNewName, 0i64);
      v13 = v9;
      if ( v9 )
      {
        v10 = (int)v12;
        v9->mNext = 0i64;
        v9[1].mNext = 0i64;
        v9[2].mNext = 0i64;
        LODWORD(v9[3].mNext) = v10;
        LODWORD(v9[4].mNext) = v10;
        HIDWORD(v9[4].mNext) = size;
        v9[5].mNext = (UFG::allocator::free_link *)p;
      }
      else
      {
        v9 = 0i64;
      }
      UFG::qBaseTreeRB::Add(&EnumBindings->mTree, (UFG::qBaseNodeRB *)v9);
    }
  }
}

