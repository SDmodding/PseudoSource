// File Line: 4
// RVA: 0x5B7F80
void __fastcall InitEnums(UFG::qTreeRB<UEL::EnumBindingEntry,UEL::EnumBindingEntry,1> *EnumBindings)
{
  UFG::qTreeRB<UEL::EnumBindingEntry,UEL::EnumBindingEntry,1> *v1; // rbp
  UFG::allocator::free_link *v2; // rdx
  unsigned int v3; // eax
  int v4; // er8
  signed int v5; // esi
  int v6; // er8
  UFG::qArray<char *,0> *v7; // rax
  UFG::allocator::free_link *v8; // rdi
  UFG::allocator::free_link *v9; // rdx
  int v10; // eax
  UFG::qSymbol result; // [rsp+50h] [rbp+8h]
  UFG::allocator::free_link *v12; // [rsp+58h] [rbp+10h]
  UFG::allocator::free_link *v13; // [rsp+60h] [rbp+18h]

  v1 = EnumBindings;
  UFG::qSymbol::create_from_string(&result, "eTargetType");
  v2 = UFG::qMalloc(0x30ui64, UFG::gGlobalNewName, 0i64);
  v12 = v2;
  if ( v2 )
  {
    v3 = result.mUID;
    v2->mNext = 0i64;
    v2[1].mNext = 0i64;
    v2[2].mNext = 0i64;
    LODWORD(v2[3].mNext) = v3;
    LODWORD(v2[4].mNext) = v3;
    HIDWORD(v2[4].mNext) = 91;
    v2[5].mNext = (UFG::allocator::free_link *)UFG::TargetTypeEnumNames;
  }
  else
  {
    v2 = 0i64;
  }
  UFG::qBaseTreeRB::Add(&v1->mTree, (UFG::qBaseNodeRB *)v2);
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
    v5 = gActionRequestEnum.m_enumLists.p[v4]->m_enumName.size;
    if ( v5 > 0 )
    {
      v6 = 0;
      while ( gActionRequestEnum.m_enumLists.p[v6]->m_listName.mUID != result.mUID )
      {
        if ( ++v6 >= gActionRequestEnum.m_enumLists.size )
        {
          v7 = 0i64;
          goto LABEL_14;
        }
      }
      v7 = &gActionRequestEnum.m_enumLists.p[v6]->m_enumName;
LABEL_14:
      v8 = (UFG::allocator::free_link *)v7->p;
      v9 = UFG::qMalloc(0x30ui64, UFG::gGlobalNewName, 0i64);
      v13 = v9;
      if ( v9 )
      {
        v10 = (signed int)v12;
        v9->mNext = 0i64;
        v9[1].mNext = 0i64;
        v9[2].mNext = 0i64;
        LODWORD(v9[3].mNext) = v10;
        LODWORD(v9[4].mNext) = v10;
        HIDWORD(v9[4].mNext) = v5;
        v9[5].mNext = v8;
      }
      else
      {
        v9 = 0i64;
      }
      UFG::qBaseTreeRB::Add(&v1->mTree, (UFG::qBaseNodeRB *)v9);
    }
  }
}

