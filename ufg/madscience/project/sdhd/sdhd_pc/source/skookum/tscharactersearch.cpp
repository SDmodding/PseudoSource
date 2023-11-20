// File Line: 187
// RVA: 0x4CBF80
void __fastcall UFG::TSCharacterSearch::~TSCharacterSearch(UFG::TSCharacterSearch *this)
{
  UFG::TSCharacterSearch *v1; // rdi
  UFG::qSymbol *v2; // rcx
  UFG::qSymbol *v3; // rbx
  UFG::eAIObjective *v4; // rcx
  UFG::qSymbol *v5; // rcx
  UFG::qSymbol *v6; // rbx

  v1 = this;
  v2 = this->mCharacterTypes.p;
  if ( v2 )
  {
    v3 = v2 - 1;
    `eh vector destructor iterator(v2, 4ui64, v2[-1].mUID, (void (__fastcall *)(void *))_);
    operator delete[](v3);
  }
  v1->mCharacterTypes.p = 0i64;
  *(_QWORD *)&v1->mCharacterTypes.size = 0i64;
  v4 = v1->mObjectives.p;
  if ( v4 )
    operator delete[](v4);
  v1->mObjectives.p = 0i64;
  *(_QWORD *)&v1->mObjectives.size = 0i64;
  v5 = v1->mFactions.p;
  if ( v5 )
  {
    v6 = v5 - 1;
    `eh vector destructor iterator(v5, 4ui64, v5[-1].mUID, (void (__fastcall *)(void *))_);
    operator delete[](v6);
  }
  v1->mFactions.p = 0i64;
  *(_QWORD *)&v1->mFactions.size = 0i64;
}

// File Line: 191
// RVA: 0x4F69D0
void __fastcall UFG::TSCharacterSearch::Mthd_constructor(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rbx
  UFG::allocator::free_link *v3; // rax
  UFG::allocator::free_link *v4; // rdx
  SSObjectBase *v5; // rcx

  v2 = pScope;
  v3 = UFG::qMalloc(0x80ui64, "TSCharacterSearch", 0i64);
  v4 = v3;
  if ( v3 )
  {
    v3->mNext = (UFG::allocator::free_link *)1097859072;
    v3[1].mNext = 0i64;
    v3[2].mNext = 0i64;
    v3[3].mNext = 0i64;
    LODWORD(v3[4].mNext) = 0;
    HIDWORD(v3[4].mNext) = -1;
    LODWORD(v3[5].mNext) = 0;
    *(UFG::allocator::free_link **)((char *)&v3[5].mNext + 4) = (UFG::allocator::free_link *)209;
    v3[8].mNext = 0i64;
    v3[7].mNext = 0i64;
    LODWORD(v3[9].mNext) = 0;
    v3[11].mNext = 0i64;
    v3[10].mNext = 0i64;
    LODWORD(v3[12].mNext) = 0;
    v3[14].mNext = 0i64;
    v3[13].mNext = 0i64;
    LODWORD(v3[15].mNext) = -1;
  }
  else
  {
    v4 = 0i64;
  }
  v5 = v2->i_scope_p.i_obj_p;
  if ( v5 && v2->i_scope_p.i_ptr_id == v5->i_ptr_id )
    v5[2].vfptr = (SSObjectBaseVtbl *)v4;
  else
    *(_QWORD *)&MEMORY[0x20] = v4;
}

// File Line: 199
// RVA: 0x4F7E10
void __fastcall UFG::TSCharacterSearch::Mthd_destructor(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rdx
  SSObjectBaseVtbl *v3; // rbx

  v2 = pScope->i_scope_p.i_obj_p;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v3 = v2[2].vfptr;
  if ( v3 )
  {
    UFG::TSCharacterSearch::~TSCharacterSearch((UFG::TSCharacterSearch *)v2[2].vfptr);
    operator delete[](v3);
  }
}

// File Line: 206
// RVA: 0x4F4790
void __fastcall UFG::TSCharacterSearch::Mthd_alive_exclude(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rdx

  v2 = pScope->i_scope_p.i_obj_p;
  if ( v2 && pScope->i_scope_p.i_ptr_id == v2->i_ptr_id )
    LODWORD(v2[2].vfptr->get_obj_type) = 2;
  else
    *(_DWORD *)(*(_QWORD *)&MEMORY[0x20] + 8i64) = 2;
}

// File Line: 213
// RVA: 0x4F47C0
void __fastcall UFG::TSCharacterSearch::Mthd_alive_include(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rdx

  v2 = pScope->i_scope_p.i_obj_p;
  if ( v2 && pScope->i_scope_p.i_ptr_id == v2->i_ptr_id )
    LODWORD(v2[2].vfptr->get_obj_type) = 1;
  else
    *(_DWORD *)(*(_QWORD *)&MEMORY[0x20] + 8i64) = 1;
}

// File Line: 220
// RVA: 0x4F9C40
void __fastcall UFG::TSCharacterSearch::Mthd_faction_exclude(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rbx
  SSObjectBaseVtbl *v3; // rbx

  v2 = pScope->i_scope_p.i_obj_p;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v3 = v2[2].vfptr;
  UFG::qArray<UFG::qSymbol,0>::Add(
    (UFG::qArray<UFG::qSymbol,0> *)&v3->get_topmost_scope,
    (UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data,
    "qArray.Add");
  LODWORD(v3->get_scope_context) = 2;
}

// File Line: 232
// RVA: 0x4F9D20
void __fastcall UFG::TSCharacterSearch::Mthd_faction_include(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rbx
  SSObjectBaseVtbl *v3; // rbx

  v2 = pScope->i_scope_p.i_obj_p;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v3 = v2[2].vfptr;
  UFG::qArray<UFG::qSymbol,0>::Add(
    (UFG::qArray<UFG::qSymbol,0> *)&v3->get_topmost_scope,
    (UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data,
    "qArray.Add");
  LODWORD(v3->get_scope_context) = 1;
}

// File Line: 244
// RVA: 0x4FACF0
void __fastcall UFG::TSCharacterSearch::Mthd_gender_exclude(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // r8
  int v3; // er9

  v2 = pScope->i_scope_p.i_obj_p;
  v3 = 0;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  LOBYTE(v3) = LODWORD((*pScope->i_data.i_array_p)->i_data_p->i_user_data) == qSymbol_Male.mUID;
  HIDWORD(v2[2].vfptr->__vecDelDtor) = v3 + 1;
}

// File Line: 262
// RVA: 0x4FAD30
void __fastcall UFG::TSCharacterSearch::Mthd_gender_include(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // r8
  int v3; // er9

  v2 = pScope->i_scope_p.i_obj_p;
  v3 = 0;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  LOBYTE(v3) = LODWORD((*pScope->i_data.i_array_p)->i_data_p->i_user_data) != qSymbol_Male.mUID;
  HIDWORD(v2[2].vfptr->__vecDelDtor) = v3 + 1;
}

// File Line: 280
// RVA: 0x500360
void __fastcall UFG::TSCharacterSearch::Mthd_indoors_exclude(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rdx

  v2 = pScope->i_scope_p.i_obj_p;
  if ( v2 && pScope->i_scope_p.i_ptr_id == v2->i_ptr_id )
    HIDWORD(v2[2].vfptr->get_obj_type) = 2;
  else
    *(_DWORD *)(*(_QWORD *)&MEMORY[0x20] + 12i64) = 2;
}

// File Line: 287
// RVA: 0x500390
void __fastcall UFG::TSCharacterSearch::Mthd_indoors_include(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rdx

  v2 = pScope->i_scope_p.i_obj_p;
  if ( v2 && pScope->i_scope_p.i_ptr_id == v2->i_ptr_id )
    HIDWORD(v2[2].vfptr->get_obj_type) = 1;
  else
    *(_DWORD *)(*(_QWORD *)&MEMORY[0x20] + 12i64) = 1;
}

// File Line: 294
// RVA: 0x5003C0
void __fastcall UFG::TSCharacterSearch::Mthd_invehicle_exclude(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rdx

  v2 = pScope->i_scope_p.i_obj_p;
  if ( v2 && pScope->i_scope_p.i_ptr_id == v2->i_ptr_id )
    LODWORD(v2[2].vfptr->is_actor) = 2;
  else
    *(_DWORD *)(*(_QWORD *)&MEMORY[0x20] + 16i64) = 2;
}

// File Line: 301
// RVA: 0x5003F0
void __fastcall UFG::TSCharacterSearch::Mthd_invehicle_include(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rdx

  v2 = pScope->i_scope_p.i_obj_p;
  if ( v2 && pScope->i_scope_p.i_ptr_id == v2->i_ptr_id )
    LODWORD(v2[2].vfptr->is_actor) = 1;
  else
    *(_DWORD *)(*(_QWORD *)&MEMORY[0x20] + 16i64) = 1;
}

// File Line: 308
// RVA: 0x505080
void __fastcall UFG::TSCharacterSearch::Mthd_objective_exclude(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rsi
  unsigned int v3; // ebp
  SSObjectBaseVtbl *v4; // rsi
  unsigned int v5; // edi
  const char **v6; // rbx
  SSInstance *v7; // r14
  unsigned int v8; // ebx
  __int64 v9; // r13
  unsigned int v10; // er14
  unsigned int v11; // ebx
  unsigned __int64 v12; // rax
  UFG::allocator::free_link *v13; // rax
  UFG::allocator::free_link *v14; // r15
  __int64 v15; // rcx
  SSInstance *(__fastcall *v16)(SSObjectBase *); // rax

  v2 = pScope->i_scope_p.i_obj_p;
  v3 = 0;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v4 = v2[2].vfptr;
  v5 = 0;
  v6 = UFG::AIObjectiveNames;
  v7 = (*pScope->i_data.i_array_p)->i_data_p;
  while ( (unsigned int)UFG::qStringCompareInsensitive(*(const char **)v7->i_user_data, *v6, -1) )
  {
    ++v5;
    ++v6;
    if ( v5 >= 0x24 )
      return;
  }
  if ( v5 != 36 && !((_QWORD)v4[1].get_obj_type & 0xFFFFFFFD) )
  {
    v8 = HIDWORD(v4[1].is_actor);
    v9 = LODWORD(v4[1].is_actor);
    v10 = v9 + 1;
    if ( (signed int)v9 + 1 > v8 )
    {
      if ( v8 )
        v11 = 2 * v8;
      else
        v11 = 1;
      for ( ; v11 < v10; v11 *= 2 )
        ;
      if ( v11 <= 4 )
        v11 = 4;
      if ( v11 - v10 > 0x10000 )
        v11 = v9 + 65537;
      if ( v11 != (_DWORD)v9 )
      {
        v12 = 4i64 * v11;
        if ( !is_mul_ok(v11, 4ui64) )
          v12 = -1i64;
        v13 = UFG::qMalloc(v12, "qArray.Add", 0i64);
        v14 = v13;
        if ( v4[1].as_instance )
        {
          if ( LODWORD(v4[1].is_actor) > 0 )
          {
            do
            {
              v15 = v3++;
              *((_DWORD *)&v13->mNext + v15) = *((_DWORD *)v4[1].as_instance + v15);
            }
            while ( v3 < LODWORD(v4[1].is_actor) );
          }
          operator delete[](v4[1].as_instance);
        }
        v4[1].as_instance = (SSInstance *(__fastcall *)(SSObjectBase *))v14;
        HIDWORD(v4[1].is_actor) = v11;
      }
    }
    v16 = v4[1].as_instance;
    LODWORD(v4[1].is_actor) = v10;
    *((_DWORD *)v16 + v9) = v5;
    LODWORD(v4[1].get_obj_type) = 2;
  }
}

// File Line: 339
// RVA: 0x5051F0
void __fastcall UFG::TSCharacterSearch::Mthd_objective_include(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rsi
  unsigned int v3; // ebp
  SSObjectBaseVtbl *v4; // rsi
  unsigned int v5; // edi
  const char **v6; // rbx
  SSInstance *v7; // r14
  unsigned int v8; // ebx
  __int64 v9; // r13
  unsigned int v10; // er14
  unsigned int v11; // ebx
  unsigned __int64 v12; // rax
  UFG::allocator::free_link *v13; // rax
  UFG::allocator::free_link *v14; // r15
  __int64 v15; // rcx
  SSInstance *(__fastcall *v16)(SSObjectBase *); // rax

  v2 = pScope->i_scope_p.i_obj_p;
  v3 = 0;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v4 = v2[2].vfptr;
  v5 = 0;
  v6 = UFG::AIObjectiveNames;
  v7 = (*pScope->i_data.i_array_p)->i_data_p;
  while ( (unsigned int)UFG::qStringCompareInsensitive(*(const char **)v7->i_user_data, *v6, -1) )
  {
    ++v5;
    ++v6;
    if ( v5 >= 0x24 )
      return;
  }
  if ( v5 != 36 && LODWORD(v4[1].get_obj_type) <= 1 )
  {
    v8 = HIDWORD(v4[1].is_actor);
    v9 = LODWORD(v4[1].is_actor);
    v10 = v9 + 1;
    if ( (signed int)v9 + 1 > v8 )
    {
      if ( v8 )
        v11 = 2 * v8;
      else
        v11 = 1;
      for ( ; v11 < v10; v11 *= 2 )
        ;
      if ( v11 <= 4 )
        v11 = 4;
      if ( v11 - v10 > 0x10000 )
        v11 = v9 + 65537;
      if ( v11 != (_DWORD)v9 )
      {
        v12 = 4i64 * v11;
        if ( !is_mul_ok(v11, 4ui64) )
          v12 = -1i64;
        v13 = UFG::qMalloc(v12, "qArray.Add", 0i64);
        v14 = v13;
        if ( v4[1].as_instance )
        {
          if ( LODWORD(v4[1].is_actor) > 0 )
          {
            do
            {
              v15 = v3++;
              *((_DWORD *)&v13->mNext + v15) = *((_DWORD *)v4[1].as_instance + v15);
            }
            while ( v3 < LODWORD(v4[1].is_actor) );
          }
          operator delete[](v4[1].as_instance);
        }
        v4[1].as_instance = (SSInstance *(__fastcall *)(SSObjectBase *))v14;
        HIDWORD(v4[1].is_actor) = v11;
      }
    }
    v16 = v4[1].as_instance;
    LODWORD(v4[1].is_actor) = v10;
    *((_DWORD *)v16 + v9) = v5;
    LODWORD(v4[1].get_obj_type) = 1;
  }
}

// File Line: 370
// RVA: 0x506A70
void __fastcall UFG::TSCharacterSearch::Mthd_scenariocontrol_exclude(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rdx

  v2 = pScope->i_scope_p.i_obj_p;
  if ( v2 && pScope->i_scope_p.i_ptr_id == v2->i_ptr_id )
    HIDWORD(v2[2].vfptr->is_actor) = 2;
  else
    *(_DWORD *)(*(_QWORD *)&MEMORY[0x20] + 20i64) = 2;
}

// File Line: 377
// RVA: 0x506AA0
void __fastcall UFG::TSCharacterSearch::Mthd_scenariocontrol_include(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rdx

  v2 = pScope->i_scope_p.i_obj_p;
  if ( v2 && pScope->i_scope_p.i_ptr_id == v2->i_ptr_id )
    HIDWORD(v2[2].vfptr->is_actor) = 1;
  else
    *(_DWORD *)(*(_QWORD *)&MEMORY[0x20] + 20i64) = 1;
}

// File Line: 384
// RVA: 0x50E490
void __fastcall UFG::TSCharacterSearch::Mthd_using_poi_exclude(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rdx

  v2 = pScope->i_scope_p.i_obj_p;
  if ( v2 && pScope->i_scope_p.i_ptr_id == v2->i_ptr_id )
    HIDWORD(v2[2].vfptr->as_instance) = 2;
  else
    *(_DWORD *)(*(_QWORD *)&MEMORY[0x20] + 28i64) = 2;
}

// File Line: 391
// RVA: 0x50E4C0
void __fastcall UFG::TSCharacterSearch::Mthd_using_poi_include(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rdx

  v2 = pScope->i_scope_p.i_obj_p;
  if ( v2 && pScope->i_scope_p.i_ptr_id == v2->i_ptr_id )
    HIDWORD(v2[2].vfptr->as_instance) = 1;
  else
    *(_DWORD *)(*(_QWORD *)&MEMORY[0x20] + 28i64) = 1;
}

// File Line: 399
// RVA: 0x50B670
void __fastcall UFG::TSCharacterSearch::Mthd_spawnpriority_exclude(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rdx
  SSObjectBaseVtbl *v3; // rdx

  v2 = pScope->i_scope_p.i_obj_p;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v3 = v2[2].vfptr;
  HIDWORD(v3->get_data_by_name) = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  LODWORD(v3->get_data_by_name) = 2;
}

// File Line: 409
// RVA: 0x50B6A0
void __fastcall UFG::TSCharacterSearch::Mthd_spawnpriority_include(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rdx
  SSObjectBaseVtbl *v3; // rdx

  v2 = pScope->i_scope_p.i_obj_p;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v3 = v2[2].vfptr;
  HIDWORD(v3->get_data_by_name) = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  LODWORD(v3->get_data_by_name) = 1;
}

// File Line: 419
// RVA: 0x50A2A0
void __fastcall UFG::TSCharacterSearch::Mthd_set_radius(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rdx

  v2 = pScope->i_scope_p.i_obj_p;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v2[2].vfptr->__vecDelDtor = (void *(__fastcall *)(SSObjectBase *, unsigned int))LODWORD((*pScope->i_data.i_array_p)->i_data_p->i_user_data);
}

// File Line: 442
// RVA: 0x4F9460
void __fastcall UFG::TSCharacterSearch::Mthd_equiped_item_exclude(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rbx
  SSObjectBaseVtbl *v3; // rbx
  SSInstance *v4; // rdx

  v2 = pScope->i_scope_p.i_obj_p;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v3 = v2[2].vfptr;
  v4 = (*pScope->i_data.i_array_p)->i_data_p;
  LODWORD(v3->set_data_by_name) = 2;
  HIDWORD(v3->set_data_by_name) = TracksEnum<unsigned long>::GetEnumFromSymbol(
                                    &UFG::gInventoryItemTracksEnum,
                                    (UFG::qSymbol *)&v4->i_user_data);
}

// File Line: 452
// RVA: 0x4F94B0
void __fastcall UFG::TSCharacterSearch::Mthd_equiped_item_include(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rbx
  SSObjectBaseVtbl *v3; // rbx
  SSInstance *v4; // rdx

  v2 = pScope->i_scope_p.i_obj_p;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v3 = v2[2].vfptr;
  v4 = (*pScope->i_data.i_array_p)->i_data_p;
  LODWORD(v3->set_data_by_name) = 1;
  HIDWORD(v3->set_data_by_name) = TracksEnum<unsigned long>::GetEnumFromSymbol(
                                    &UFG::gInventoryItemTracksEnum,
                                    (UFG::qSymbol *)&v4->i_user_data);
}

// File Line: 462
// RVA: 0x4F6210
void __fastcall UFG::TSCharacterSearch::Mthd_character_type_exclude(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rdx
  SSObjectBaseVtbl *v3; // rbp
  SSData **v4; // rdx
  unsigned int *v5; // r8
  SSInstance *v6; // rcx
  unsigned int v7; // eax
  __int64 *v8; // r14
  __int64 v9; // r12
  __int64 v10; // r15
  unsigned int v11; // edx
  __int64 v12; // rsi
  unsigned int v13; // ebx
  unsigned int v14; // edx
  SSInvokedContextBase *(__fastcall *v15)(SSObjectBase *); // rcx

  v2 = pScope->i_scope_p.i_obj_p;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v3 = v2[2].vfptr;
  v4 = pScope->i_data.i_array_p;
  v5 = (unsigned int *)(*v4)->i_data_p->i_user_data;
  v6 = v4[1]->i_data_p;
  if ( v6 )
    v7 = (unsigned int)v6[1].i_class_p;
  else
    v7 = UFG::gNullQSymbol.mUID;
  LODWORD(v3[1].get_topmost_scope) = v7;
  v8 = (__int64 *)*((_QWORD *)v5 + 1);
  if ( *v5 )
  {
    v9 = *v5;
    do
    {
      v10 = LODWORD(v3[1].set_data_by_name);
      v11 = HIDWORD(v3[1].set_data_by_name);
      v12 = *v8;
      v13 = v10 + 1;
      if ( (signed int)v10 + 1 > v11 )
      {
        if ( v11 )
          v14 = 2 * v11;
        else
          v14 = 1;
        for ( ; v14 < v13; v14 *= 2 )
          ;
        if ( v14 <= 4 )
          v14 = 4;
        if ( v14 - v13 > 0x10000 )
          v14 = v10 + 65537;
        UFG::qArray<UFG::qSymbol,0>::Reallocate(
          (UFG::qArray<UFG::qSymbol,0> *)&v3[1].set_data_by_name,
          v14,
          "qArray.Add");
      }
      v15 = v3[1].get_scope_context;
      LODWORD(v3[1].set_data_by_name) = v13;
      ++v8;
      *((_DWORD *)v15 + v10) = *(_DWORD *)(v12 + 32);
      --v9;
    }
    while ( v9 );
  }
  LODWORD(v3[1].get_data_by_name) = 2;
}

// File Line: 493
// RVA: 0x4F6330
void __fastcall UFG::TSCharacterSearch::Mthd_character_type_include(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rdx
  SSObjectBaseVtbl *v3; // rbp
  SSData **v4; // rdx
  unsigned int *v5; // r8
  SSInstance *v6; // rcx
  unsigned int v7; // eax
  __int64 *v8; // r14
  __int64 v9; // r12
  __int64 v10; // r15
  unsigned int v11; // edx
  __int64 v12; // rsi
  unsigned int v13; // ebx
  unsigned int v14; // edx
  SSInvokedContextBase *(__fastcall *v15)(SSObjectBase *); // rcx

  v2 = pScope->i_scope_p.i_obj_p;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v3 = v2[2].vfptr;
  v4 = pScope->i_data.i_array_p;
  v5 = (unsigned int *)(*v4)->i_data_p->i_user_data;
  v6 = v4[1]->i_data_p;
  if ( v6 )
    v7 = (unsigned int)v6[1].i_class_p;
  else
    v7 = UFG::gNullQSymbol.mUID;
  LODWORD(v3[1].get_topmost_scope) = v7;
  v8 = (__int64 *)*((_QWORD *)v5 + 1);
  if ( *v5 )
  {
    v9 = *v5;
    do
    {
      v10 = LODWORD(v3[1].set_data_by_name);
      v11 = HIDWORD(v3[1].set_data_by_name);
      v12 = *v8;
      v13 = v10 + 1;
      if ( (signed int)v10 + 1 > v11 )
      {
        if ( v11 )
          v14 = 2 * v11;
        else
          v14 = 1;
        for ( ; v14 < v13; v14 *= 2 )
          ;
        if ( v14 <= 4 )
          v14 = 4;
        if ( v14 - v13 > 0x10000 )
          v14 = v10 + 65537;
        UFG::qArray<UFG::qSymbol,0>::Reallocate(
          (UFG::qArray<UFG::qSymbol,0> *)&v3[1].set_data_by_name,
          v14,
          "qArray.Add");
      }
      v15 = v3[1].get_scope_context;
      LODWORD(v3[1].set_data_by_name) = v13;
      ++v8;
      *((_DWORD *)v15 + v10) = *(_DWORD *)(v12 + 32);
      --v9;
    }
    while ( v9 );
  }
  LODWORD(v3[1].get_data_by_name) = 1;
}

// File Line: 525
// RVA: 0x4DF510
void __fastcall UFG::TSCharacterSearch::DoSearch(UFG::TSCharacterSearch *search, UFG::TSCharacter *_searchCharacter, SSList *previousList, SSInstance **ppResult)
{
  SSList *v4; // r12
  _DWORD *v5; // r14
  UFG::SimObject *v6; // r13
  UFG::TransformNodeComponent *v7; // rbx
  float v8; // xmm1_4
  float v9; // xmm2_4
  __int64 v10; // rbx
  UFG::allocator::free_link *v11; // rsi
  unsigned int v12; // edi
  unsigned int v13; // er15
  __int64 v14; // r14
  __int64 v15; // rdx
  __int64 v16; // r12
  unsigned int v17; // ecx
  unsigned int v18; // er13
  unsigned int v19; // ebx
  unsigned __int64 v20; // rax
  UFG::allocator::free_link *v21; // rax
  UFG::allocator::free_link *v22; // r15
  UFG::allocator::free_link *v23; // rcx
  __int64 v24; // rdx
  float v25; // xmm6_4
  UFG::qNode<UFG::SimObjectCharacterPropertiesComponent,UFG::SimObjectCharacterPropertiesComponent> *v26; // r12
  UFG::qNode<UFG::SimObjectCharacterPropertiesComponent,UFG::SimObjectCharacterPropertiesComponent> *v27; // rbx
  UFG::TransformNodeComponent *v28; // rbx
  unsigned int v29; // ecx
  unsigned int v30; // er13
  unsigned int v31; // ebx
  unsigned __int64 v32; // rax
  UFG::allocator::free_link *v33; // rax
  UFG::allocator::free_link *v34; // r15
  UFG::allocator::free_link *v35; // rcx
  __int64 v36; // rdx
  float v37; // er13
  __int64 v38; // r15
  unsigned __int64 v39; // rax
  UFG::allocator::free_link *v40; // rax
  unsigned int v41; // er12
  UFG::allocator::free_link *v42; // r14
  unsigned int v43; // edx
  UFG::qBaseTreeRB *v44; // rax
  float v45; // ecx
  float v46; // er15
  unsigned int v47; // ebx
  unsigned __int64 v48; // rax
  UFG::allocator::free_link *v49; // rax
  UFG::allocator::free_link *v50; // r12
  UFG::allocator::free_link *v51; // rdx
  __int64 v52; // r8
  __int64 v53; // r12
  UFG::SimObjectCVBase *v54; // r15
  __int64 v55; // rdx
  UFG::ActiveAIEntityComponent *v56; // rax
  UFG::eAIObjective v57; // er9
  unsigned int v58; // ecx
  unsigned int v59; // edx
  UFG::SimObjectCharacterPropertiesComponent *v60; // rax
  bool v61; // zf
  UFG::SimObjectCharacterPropertiesComponent *v62; // rax
  unsigned int v63; // ecx
  unsigned int v64; // edx
  int v65; // eax
  bool v66; // al
  bool v67; // cl
  UFG::BaseCameraComponent *v68; // rcx
  UFG::Camera *v69; // rax
  UFG::qMatrix44 *v70; // rbx
  UFG::qMatrix44 *v71; // rax
  float v72; // xmm8_4
  float v73; // xmm9_4
  float v74; // xmm10_4
  float v75; // xmm11_4
  float v76; // xmm12_4
  float v77; // xmm14_4
  float v78; // xmm15_4
  float v79; // ST40_4
  float v80; // ST3C_4
  float v81; // xmm0_4
  float v82; // xmm0_4
  float v83; // xmm0_4
  __m128 v84; // xmm2
  float v85; // xmm5_4
  float v86; // xmm0_4
  __m128 v87; // xmm2
  float v88; // xmm4_4
  float v89; // xmm6_4
  float v90; // xmm0_4
  __m128 v91; // xmm2
  float v92; // xmm4_4
  float v93; // xmm3_4
  UFG::TransformNodeComponent *v94; // rbx
  int v95; // ecx
  UFG::SimComponent *v96; // rax
  bool v97; // al
  unsigned int v98; // eax
  UFG::StreamedResourceComponent *v99; // rcx
  bool v100; // al
  bool v101; // bl
  UFG::SimComponent *v102; // r8
  UFG::SimObject *v103; // rcx
  UFG::SimComponent *v104; // rax
  int v105; // eax
  bool v106; // dl
  UFG::SimComponent *v107; // r8
  UFG::SimObject *v108; // rcx
  unsigned __int16 v109; // dx
  UFG::SimComponent *v110; // rax
  UFG::qPropertySet *v111; // rax
  char v112; // al
  int v113; // ecx
  bool v114; // bl
  UFG::SceneObjectProperties *v115; // rax
  UFG::qPropertySet *v116; // rcx
  UFG::qPropertySet *v117; // rax
  char *v118; // rax
  __int64 v119; // rcx
  UFG::qPropertyList *v120; // rcx
  unsigned int v121; // er15
  UFG::qSymbol *v122; // r11
  unsigned int v123; // er10
  unsigned int v124; // edx
  unsigned int v125; // ecx
  char v126; // al
  unsigned int v127; // ebx
  __int64 v128; // r15
  SSList *v129; // rax
  SSList *v130; // rbx
  __int64 i; // r14
  UFG::allocator::free_link *v132; // rax
  UFG::TSActorComponent *v133; // rcx
  UFG::TSActor *v134; // r12
  __int64 v135; // rdi
  SSInstance **v136; // r15
  unsigned __int64 v137; // rax
  SSActor **v138; // rax
  __int64 v139; // rax
  ARefCountMix<SSInstance> **v140; // rdi
  unsigned __int64 j; // r14
  SSInstance *v142; // rax
  unsigned int v143; // [rsp+20h] [rbp-A0h]
  UFG::allocator::free_link *v144; // [rsp+28h] [rbp-98h]
  __int64 v145; // [rsp+30h] [rbp-90h]
  __int64 v146; // [rsp+30h] [rbp-90h]
  UFG::SimObjectCVBase *v147; // [rsp+48h] [rbp-78h]
  UFG::qMatrix44 result; // [rsp+50h] [rbp-70h]
  UFG::qVector4 planes; // [rsp+90h] [rbp-30h]
  float v150; // [rsp+A0h] [rbp-20h]
  float v151; // [rsp+A4h] [rbp-1Ch]
  float v152; // [rsp+A8h] [rbp-18h]
  float v153; // [rsp+ACh] [rbp-14h]
  float v154; // [rsp+B0h] [rbp-10h]
  float v155; // [rsp+B4h] [rbp-Ch]
  float v156; // [rsp+B8h] [rbp-8h]
  float v157; // [rsp+BCh] [rbp-4h]
  float v158; // [rsp+C0h] [rbp+0h]
  float v159; // [rsp+C4h] [rbp+4h]
  float v160; // [rsp+C8h] [rbp+8h]
  float v161; // [rsp+CCh] [rbp+Ch]
  float v162; // [rsp+D0h] [rbp+10h]
  float v163; // [rsp+D4h] [rbp+14h]
  float v164; // [rsp+D8h] [rbp+18h]
  float v165; // [rsp+DCh] [rbp+1Ch]
  float v166; // [rsp+E0h] [rbp+20h]
  float v167; // [rsp+E4h] [rbp+24h]
  float v168; // [rsp+E8h] [rbp+28h]
  float v169; // [rsp+ECh] [rbp+2Ch]
  UFG::TransformNodeComponent *v170; // [rsp+F0h] [rbp+30h]
  __int64 v171; // [rsp+F8h] [rbp+38h]
  UFG::Camera *v172; // [rsp+1F0h] [rbp+130h]
  UFG::allocator::free_link *v173; // [rsp+1F8h] [rbp+138h]
  SSList *v174; // [rsp+200h] [rbp+140h]
  SSInstance **v175; // [rsp+208h] [rbp+148h]

  v171 = -2i64;
  v4 = previousList;
  v5 = (_DWORD *)&search->mRadius;
  v6 = _searchCharacter->mpSimObj.m_pPointer;
  v147 = (UFG::SimObjectCVBase *)v6;
  if ( v6 && (v6->m_Flags >> 14) & 1 )
  {
    v7 = (UFG::TransformNodeComponent *)v6->m_Components.p[2].m_pComponent;
  }
  else
  {
    v147 = 0i64;
    v7 = 0i64;
  }
  UFG::TransformNodeComponent::UpdateWorldTransform(v7);
  v8 = v7->mWorldTransform.v3.y;
  v9 = v7->mWorldTransform.v3.z;
  result.v2.x = v7->mWorldTransform.v3.x;
  result.v2.y = v8;
  result.v2.z = v9;
  v10 = 0i64;
  v11 = 0i64;
  v144 = 0i64;
  v12 = 0;
  v143 = 0;
  v13 = 0;
  if ( v4 )
  {
    if ( v4->i_items.i_count )
    {
      v14 = 0i64;
      v15 = v4->i_items.i_count;
      v145 = v4->i_items.i_count;
      do
      {
        v16 = *(_QWORD *)&v4->i_items.i_array_p[v14][4].i_ref_count;
        if ( !v16 || !((*(_WORD *)(v16 + 76) >> 14) & 1) )
          v16 = 0i64;
        v17 = v12;
        v18 = v12 + 1;
        if ( v12 + 1 > v13 )
        {
          v19 = 1;
          if ( v13 )
            v19 = 2 * v13;
          for ( ; v19 < v18; v19 *= 2 )
            ;
          if ( v19 <= 2 )
            v19 = 2;
          if ( v19 - v18 > 0x10000 )
            v19 = v12 + 65537;
          if ( v19 == v12 )
          {
            v10 = 0i64;
          }
          else
          {
            v20 = 8i64 * v19;
            if ( !is_mul_ok(v19, 8ui64) )
              v20 = -1i64;
            v21 = UFG::qMalloc(v20, "qArray.Add", 0i64);
            v22 = v21;
            if ( v11 )
            {
              if ( v12 )
              {
                v23 = v21;
                v24 = v12;
                do
                {
                  v23->mNext = *(UFG::allocator::free_link **)((char *)v23 + (char *)v11 - (char *)v21);
                  ++v23;
                  --v24;
                }
                while ( v24 );
              }
              operator delete[](v11);
            }
            v11 = v22;
            v144 = v22;
            v13 = v19;
            v15 = v145;
            v17 = v12;
            v10 = 0i64;
          }
        }
        ++v12;
        v143 = v18;
        v11[v17].mNext = (UFG::allocator::free_link *)v16;
        ++v14;
        v145 = --v15;
        v4 = v174;
      }
      while ( v15 );
LABEL_60:
      v5 = (_DWORD *)&v172->mFOVOffset;
      goto LABEL_61;
    }
  }
  else
  {
    v25 = *(float *)v5 * *(float *)v5;
    v26 = UFG::SimObjectCharacterPropertiesComponent::s_SimObjectCharacterPropertiesComponentList.mNode.mNext - 10;
    if ( (UFG::qList<UFG::SimObjectCharacterPropertiesComponent,UFG::SimObjectCharacterPropertiesComponent,1,0> *)&UFG::SimObjectCharacterPropertiesComponent::s_SimObjectCharacterPropertiesComponentList.mNode.mNext[-10] != &UFG::SimObjectCharacterPropertiesComponent::s_SimObjectCharacterPropertiesComponentList - 10 )
    {
      do
      {
        if ( !((LOBYTE(v26[2].mPrev) >> 1) & 1) )
        {
          v27 = v26[2].mNext;
          v28 = (UFG::TransformNodeComponent *)(v27 ? v27[5].mNext : 0i64);
          if ( v28 )
          {
            UFG::TransformNodeComponent::UpdateWorldTransform(v28);
            if ( (float)((float)((float)((float)(result.v2.x - v28->mWorldTransform.v3.x)
                                       * (float)(result.v2.x - v28->mWorldTransform.v3.x))
                               + (float)((float)(result.v2.y - v28->mWorldTransform.v3.y)
                                       * (float)(result.v2.y - v28->mWorldTransform.v3.y)))
                       + (float)((float)(result.v2.z - v28->mWorldTransform.v3.z)
                               * (float)(result.v2.z - v28->mWorldTransform.v3.z))) <= v25 )
            {
              v173 = (UFG::allocator::free_link *)v26[2].mNext;
              v29 = v12;
              v30 = v12 + 1;
              if ( v12 + 1 > v13 )
              {
                v31 = 1;
                if ( v13 )
                  v31 = 2 * v13;
                for ( ; v31 < v30; v31 *= 2 )
                  ;
                if ( v31 <= 2 )
                  v31 = 2;
                if ( v31 - v30 > 0x10000 )
                  v31 = v12 + 65537;
                if ( v31 != v12 )
                {
                  v32 = 8i64 * v31;
                  if ( !is_mul_ok(v31, 8ui64) )
                    v32 = -1i64;
                  v33 = UFG::qMalloc(v32, "qArray.Add", 0i64);
                  v34 = v33;
                  if ( v11 )
                  {
                    if ( v12 )
                    {
                      v35 = v33;
                      v36 = v12;
                      do
                      {
                        v35->mNext = *(UFG::allocator::free_link **)((char *)v35 + (char *)v11 - (char *)v33);
                        ++v35;
                        --v36;
                      }
                      while ( v36 );
                    }
                    operator delete[](v11);
                  }
                  v11 = v34;
                  v144 = v34;
                  v13 = v31;
                  v29 = v12;
                }
              }
              ++v12;
              v143 = v30;
              v11[v29].mNext = v173;
            }
          }
        }
        v26 = v26[10].mNext - 10;
      }
      while ( v26 != (UFG::qNode<UFG::SimObjectCharacterPropertiesComponent,UFG::SimObjectCharacterPropertiesComponent> *)(&UFG::SimObjectCharacterPropertiesComponent::s_SimObjectCharacterPropertiesComponentList - 10) );
      v10 = 0i64;
      goto LABEL_60;
    }
  }
LABEL_61:
  *(_QWORD *)&result.v1.x = 0i64;
  v37 = 0.0;
  *(_QWORD *)&result.v0.z = 0i64;
  if ( v5[3] )
  {
    v38 = UFG::TSGameSlice::msInteriorTriggerData.size;
    if ( UFG::TSGameSlice::msInteriorTriggerData.size )
    {
      v39 = 8i64 * UFG::TSGameSlice::msInteriorTriggerData.size;
      if ( !is_mul_ok(UFG::TSGameSlice::msInteriorTriggerData.size, 8ui64) )
        v39 = -1i64;
      v40 = UFG::qMalloc(v39, "qArray.Reallocate(Reserve)", 0i64);
      *(_QWORD *)&result.v1.x = v40;
      v41 = v38;
      LODWORD(result.v0.w) = v38;
      if ( (_DWORD)v38 )
      {
        v173 = 0i64;
        v146 = v38;
        v42 = v40;
        do
        {
          v43 = *(unsigned int *)((char *)&UFG::TSGameSlice::msInteriorTriggerData.p->mTriggerName.mUID + v10);
          if ( v43 )
          {
            v44 = UFG::qBaseTreeRB::Get(&UFG::TriggerRegion::msTriggerRegions.mTree, v43);
            if ( v44 )
            {
              *(_QWORD *)&result.v1.z = (char *)v44 - 112;
              if ( v44 != (UFG::qBaseTreeRB *)112 )
              {
                v45 = v37;
                LODWORD(v46) = LODWORD(v37) + 1;
                if ( LODWORD(v37) + 1 > v41 )
                {
                  v47 = 1;
                  if ( v41 )
                    v47 = 2 * v41;
                  for ( ; v47 < LODWORD(v46); v47 *= 2 )
                    ;
                  if ( v47 <= 2 )
                    v47 = 2;
                  if ( v47 - LODWORD(v46) > 0x10000 )
                    v47 = LODWORD(v37) + 65537;
                  if ( v47 != LODWORD(v37) )
                  {
                    v48 = 8i64 * v47;
                    if ( !is_mul_ok(v47, 8ui64) )
                      v48 = -1i64;
                    v49 = UFG::qMalloc(v48, "qArray.Add", 0i64);
                    v50 = v49;
                    if ( v42 )
                    {
                      if ( v37 != 0.0 )
                      {
                        v51 = v49;
                        v52 = LODWORD(v37);
                        do
                        {
                          v51->mNext = *(UFG::allocator::free_link **)((char *)v51 + (char *)v42 - (char *)v49);
                          ++v51;
                          --v52;
                        }
                        while ( v52 );
                      }
                      operator delete[](v42);
                    }
                    v42 = v50;
                    *(_QWORD *)&result.v1.x = v50;
                    v41 = v47;
                    LODWORD(result.v0.w) = v47;
                    v45 = v37;
                  }
                  v10 = (__int64)v173;
                }
                ++LODWORD(v37);
                result.v0.z = v46;
                v42[LODWORD(v45)] = *(UFG::allocator::free_link *)&result.v1.z;
                v38 = v146;
              }
            }
          }
          v10 += 168i64;
          v173 = (UFG::allocator::free_link *)v10;
          v146 = --v38;
        }
        while ( v38 );
        v12 = v143;
        v11 = v144;
        v5 = (_DWORD *)&v172->mFOVOffset;
        LODWORD(v10) = 0;
      }
    }
  }
  v53 = (signed int)(v12 - 1);
  *(_QWORD *)&result.v1.z = (signed int)(v12 - 1);
  if ( (signed int)(v12 - 1) >= 0 )
  {
    while ( 1 )
    {
      v54 = (UFG::SimObjectCVBase *)v11[v53].mNext;
      if ( v54 == v147 )
        goto LABEL_94;
      if ( v5[18] )
      {
        if ( v54 )
        {
          v56 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>((UFG::SimObjectCVBase *)v11[v53].mNext);
          if ( v56 )
          {
            v57 = v56->m_CurrentObjective;
            v58 = v10;
            v59 = v5[20];
            if ( v5[18] == 1 )
            {
              if ( !v59 )
                goto LABEL_94;
              while ( v57 != *(_DWORD *)(*((_QWORD *)v5 + 11) + 4i64 * v58) )
              {
                if ( ++v58 >= v59 )
                  goto LABEL_94;
              }
              if ( v58 == -1 )
                goto LABEL_94;
            }
            else if ( v59 )
            {
              while ( v57 != *(_DWORD *)(*((_QWORD *)v5 + 11) + 4i64 * v58) )
              {
                if ( ++v58 >= v59 )
                  goto LABEL_112;
              }
              if ( v58 != -1 )
                goto LABEL_94;
            }
          }
        }
      }
LABEL_112:
      if ( v5[1] )
      {
        if ( v54 )
        {
          v60 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v54);
          if ( v60 )
          {
            v61 = v5[1] == 1 ? v60->m_eGender == 1 : v60->m_eGender == 2;
            if ( !v61 )
              goto LABEL_94;
          }
        }
      }
      if ( v5[12] )
      {
        if ( v54 )
        {
          v62 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v54);
          if ( v62 )
          {
            v63 = v10;
            v64 = v5[14];
            if ( v5[12] == 1 )
            {
              if ( !v64 )
                goto LABEL_94;
              while ( v62->m_symFactionClass.mUID != *(_DWORD *)(*((_QWORD *)v5 + 8) + 4i64 * v63) )
              {
                if ( ++v63 >= v64 )
                  goto LABEL_94;
              }
              if ( v63 == -1 )
                goto LABEL_94;
            }
            else if ( v64 )
            {
              while ( v62->m_symFactionClass.mUID != *(_DWORD *)(*((_QWORD *)v5 + 8) + 4i64 * v63) )
              {
                if ( ++v63 >= v64 )
                  goto LABEL_134;
              }
              if ( v63 != -1 )
                goto LABEL_94;
            }
          }
        }
      }
LABEL_134:
      v65 = v5[2];
      if ( v65 )
      {
        if ( v65 == 1 )
        {
          v66 = UFG::IsKnockedOut((UFG::SimObject *)&v54->vfptr) == 0;
        }
        else
        {
          if ( v65 != 2 )
            goto LABEL_94;
          v66 = UFG::IsKnockedOut((UFG::SimObject *)&v54->vfptr);
        }
        if ( !v66 )
          goto LABEL_94;
      }
      if ( v5[6] )
      {
        v67 = 1;
        if ( v54 )
        {
          v170 = (UFG::TransformNodeComponent *)v54->m_Components.p[2].m_pComponent;
          if ( v170 )
          {
            v68 = UFG::Director::Get()->mCurrentCamera;
            v69 = &v68->mCamera;
            if ( !v68 )
              v69 = 0i64;
            v172 = v69;
            v70 = UFG::Camera::GetViewProjection(v69);
            v71 = UFG::Camera::GetWorldView(v172);
            UFG::qMatrix44::operator*(v71, &result, v70);
            LODWORD(v72) = COERCE_UNSIGNED_INT(result.v0.x + result.v0.w) ^ _xmm[0];
            LODWORD(v73) = COERCE_UNSIGNED_INT(result.v1.x + result.v1.w) ^ _xmm[0];
            LODWORD(v74) = COERCE_UNSIGNED_INT(result.v2.x + result.v2.w) ^ _xmm[0];
            LODWORD(v75) = COERCE_UNSIGNED_INT(result.v0.w - result.v0.x) ^ _xmm[0];
            LODWORD(v76) = COERCE_UNSIGNED_INT(result.v1.w - result.v1.x) ^ _xmm[0];
            LODWORD(v77) = COERCE_UNSIGNED_INT(result.v2.w - result.v2.x) ^ _xmm[0];
            LODWORD(v172) = COERCE_UNSIGNED_INT(result.v3.w - result.v3.x) ^ _xmm[0];
            LODWORD(v78) = COERCE_UNSIGNED_INT(result.v0.y + result.v0.w) ^ _xmm[0];
            LODWORD(v174) = COERCE_UNSIGNED_INT(result.v1.y + result.v1.w) ^ _xmm[0];
            LODWORD(v173) = COERCE_UNSIGNED_INT(result.v2.y + result.v2.w) ^ _xmm[0];
            LODWORD(result.v0.x) = COERCE_UNSIGNED_INT(result.v3.y + result.v3.w) ^ _xmm[0];
            LODWORD(v79) = COERCE_UNSIGNED_INT(result.v1.w - result.v1.y) ^ _xmm[0] ^ _xmm[0];
            HIDWORD(v147) = COERCE_UNSIGNED_INT(result.v3.w - result.v3.y) ^ _xmm[0];
            LODWORD(v80) = COERCE_UNSIGNED_INT(result.v2.w - result.v2.z) ^ _xmm[0];
            LODWORD(v147) = COERCE_UNSIGNED_INT(result.v1.w - result.v1.z) ^ _xmm[0];
            v81 = fsqrt(
                    (float)((float)(COERCE_FLOAT(LODWORD(result.v1.z) ^ _xmm[0])
                                  * COERCE_FLOAT(LODWORD(result.v1.z) ^ _xmm[0]))
                          + (float)(COERCE_FLOAT(LODWORD(result.v0.z) ^ _xmm[0])
                                  * COERCE_FLOAT(LODWORD(result.v0.z) ^ _xmm[0])))
                  + (float)(COERCE_FLOAT(LODWORD(result.v2.z) ^ _xmm[0]) * COERCE_FLOAT(LODWORD(result.v2.z) ^ _xmm[0])));
            planes.x = COERCE_FLOAT(LODWORD(result.v0.z) ^ _xmm[0]) * (float)(1.0 / v81);
            planes.y = COERCE_FLOAT(LODWORD(result.v1.z) ^ _xmm[0]) * (float)(1.0 / v81);
            planes.z = COERCE_FLOAT(LODWORD(result.v2.z) ^ _xmm[0]) * (float)(1.0 / v81);
            planes.w = COERCE_FLOAT(LODWORD(result.v3.z) ^ _xmm[0]) * (float)(1.0 / v81);
            v82 = fsqrt((float)((float)(v73 * v73) + (float)(v72 * v72)) + (float)(v74 * v74));
            v150 = (float)(1.0 / v82) * v72;
            v151 = (float)(1.0 / v82) * v73;
            v152 = (float)(1.0 / v82) * v74;
            v153 = (float)(1.0 / v82) * COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v3.x + result.v3.w) ^ _xmm[0]);
            v83 = fsqrt((float)((float)(v76 * v76) + (float)(v75 * v75)) + (float)(v77 * v77));
            v154 = (float)(1.0 / v83) * v75;
            v155 = (float)(1.0 / v83) * v76;
            v156 = (float)(1.0 / v83) * v77;
            v157 = (float)(1.0 / v83) * *(float *)&v172;
            v84 = (__m128)(unsigned int)v174;
            LODWORD(v85) = COERCE_UNSIGNED_INT(result.v2.y + result.v2.w) ^ _xmm[0];
            v84.m128_f32[0] = (float)((float)(v84.m128_f32[0] * v84.m128_f32[0]) + (float)(v78 * v78))
                            + (float)(v85 * v85);
            LODWORD(v86) = (unsigned __int128)_mm_sqrt_ps(v84);
            v158 = (float)(1.0 / v86) * v78;
            v159 = (float)(1.0 / v86) * *(float *)&v174;
            v160 = (float)(1.0 / v86) * v85;
            v161 = (float)(1.0 / v86) * result.v0.x;
            v87 = (__m128)LODWORD(v79);
            LODWORD(v88) = COERCE_UNSIGNED_INT(result.v0.w - result.v0.y) ^ _xmm[0];
            LODWORD(v89) = COERCE_UNSIGNED_INT(result.v1.w - result.v1.y) ^ _xmm[0] ^ _xmm[0];
            v87.m128_f32[0] = (float)((float)(v87.m128_f32[0] * v87.m128_f32[0]) + (float)(v88 * v88))
                            + (float)(v89 * v89);
            LODWORD(v90) = (unsigned __int128)_mm_sqrt_ps(v87);
            v162 = (float)(1.0 / v90) * v88;
            v163 = (float)(1.0 / v90) * v79;
            v164 = (float)(1.0 / v90) * v89;
            v165 = (float)(1.0 / v90) * *((float *)&v147 + 1);
            v91 = (__m128)(unsigned int)v147;
            LODWORD(v92) = COERCE_UNSIGNED_INT(result.v0.w - result.v0.z) ^ _xmm[0];
            v91.m128_f32[0] = (float)((float)(v91.m128_f32[0] * v91.m128_f32[0]) + (float)(v92 * v92))
                            + (float)(v80 * v80);
            v93 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v91));
            v166 = v93 * v92;
            v167 = v93 * *(float *)&v147;
            v168 = v80 * v93;
            v169 = COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v3.w - result.v3.z) ^ _xmm[0]) * v93;
            v94 = v170;
            UFG::TransformNodeComponent::UpdateWorldTransform(v170);
            v67 = IntersectSphereFrustum(&planes, (UFG::qVector3 *)&v94->mWorldTransform.v3, 2.0) != 2;
          }
        }
        if ( v5[6] != 1 )
          v67 = v67 == 0;
        if ( !v67 )
          break;
      }
      v95 = v5[4];
      if ( v95 )
      {
        LODWORD(v10) = 0;
        if ( v54 )
          v96 = v54->m_Components.p[44].m_pComponent;
        else
          v96 = 0i64;
        v97 = v96 != 0i64;
        if ( v95 != 1 )
          v97 = v97 == 0;
        if ( !v97 )
          goto LABEL_94;
      }
      if ( v5[8] )
      {
        v98 = UFG::gNullQSymbol.mUID;
        if ( v54 )
        {
          v99 = (UFG::StreamedResourceComponent *)v54->m_Components.p[10].m_pComponent;
          if ( v99 )
            v98 = UFG::StreamedResourceComponent::GetSpawnPriority(v99, 0i64)->mUID;
        }
        v100 = v98 == v5[9];
        if ( v5[8] == 2 )
          v100 = v100 == 0;
        if ( !v100 )
          break;
      }
      if ( v5[10] )
      {
        v101 = 0;
        if ( !(dword_14240D784 & 1) )
        {
          dword_14240D784 |= 1u;
          dword_14240D780 = UFG::InventoryComponent::GetSlotTarget(0);
        }
        if ( v54 )
        {
          v102 = v54->m_Components.p[20].m_pComponent;
          if ( v102 )
          {
            v103 = *(UFG::SimObject **)(56i64
                                      * *(unsigned __int8 *)(*(_QWORD *)&v102[1].m_Flags
                                                           + (unsigned int)dword_14240D780
                                                           + 8i64)
                                      + *(_QWORD *)&v102[1].m_TypeUID
                                      + 40);
            if ( v103 )
            {
              v104 = UFG::SimObject::GetComponentOfType(v103, UFG::InventoryItemComponent::_TypeUID);
              if ( v104 )
              {
                v105 = (int)v104[1].m_pSimObject;
                v101 = v105 && v5[11] == v105;
              }
            }
          }
        }
        if ( v5[10] != 1 )
          v101 = v101 == 0;
        if ( !v101 )
          break;
      }
      if ( v5[7] )
      {
        v106 = 0;
        if ( v54 )
        {
          v107 = v54->m_Components.p[20].m_pComponent;
          if ( v107 )
          {
            v108 = *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v107[1].m_Flags + 34i64)
                                      + *(_QWORD *)&v107[1].m_TypeUID
                                      + 40);
            if ( v108 )
            {
              v109 = v108->m_Flags;
              if ( (v109 >> 14) & 1 )
              {
                v110 = v108->m_Components.p[25].m_pComponent;
              }
              else if ( (v109 & 0x8000u) == 0 )
              {
                if ( (v109 >> 13) & 1 )
                {
                  v110 = v108->m_Components.p[10].m_pComponent;
                }
                else if ( (v109 >> 12) & 1 )
                {
                  v110 = v108->m_Components.p[3].m_pComponent;
                }
                else
                {
                  v110 = UFG::SimObject::GetComponentOfType(v108, UFG::InterestPoint::_TypeUID);
                }
              }
              else
              {
                v110 = v108->m_Components.p[25].m_pComponent;
              }
              v106 = v110 != 0i64;
            }
          }
        }
        if ( v5[7] != 1 )
          v106 = v106 == 0;
        if ( !v106 )
          break;
      }
      if ( v5[5] )
      {
        v111 = PropertyUtils::Get<bool>(v54->m_pSceneObj, (UFG::qSymbol *)&qSymbol_ScenarioControl.mUID);
        if ( v111 )
        {
          v112 = v111->mFlags;
        }
        else
        {
          PropertyUtils::SetRuntime<bool>(v54->m_pSceneObj, (UFG::qSymbol *)&qSymbol_ScenarioControl.mUID, 0);
          v112 = 0;
        }
        v113 = v5[5];
        if ( v113 != 1 )
        {
          if ( v113 != 2 )
            break;
          v112 = v112 == 0;
        }
        if ( !v112 )
          break;
      }
      if ( v5[24] )
      {
        v114 = 0;
        v115 = v54->m_pSceneObj;
        v116 = v115->mpWritableProperties;
        if ( !v116 )
          v116 = v115->mpConstProperties;
        v117 = UFG::qPropertySet::Get<UFG::qPropertySet>(
                 v116,
                 (UFG::qSymbol *)&schema_classlist::sPropertyName.mUID,
                 DEPTH_RECURSE);
        if ( v117 )
        {
          v118 = UFG::qPropertySet::GetMemImagePtr(v117);
          if ( v118 )
          {
            v119 = *((_QWORD *)v118 + 1);
            if ( v119 )
            {
              v120 = (UFG::qPropertyList *)&v118[v119 + 8];
              if ( v120 )
              {
                v121 = v120->mNumElements;
                v122 = v121 ? UFG::qPropertyList::Get<UFG::qSymbol>(v120, 0) : 0i64;
                v123 = 0;
                if ( v121 )
                {
                  v124 = v5[26];
                  do
                  {
                    v125 = 0;
                    if ( v124 )
                    {
                      while ( v122[v123].mUID != *(_DWORD *)(*((_QWORD *)v5 + 14) + 4i64 * v125) )
                      {
                        if ( ++v125 >= v124 )
                          goto LABEL_218;
                      }
                    }
                    else
                    {
LABEL_218:
                      v125 = -1;
                    }
                    v114 = v125 != -1;
                    if ( v125 != -1 )
                      break;
                    ++v123;
                  }
                  while ( v123 < v121 );
                  v53 = *(_QWORD *)&result.v1.z;
                  v37 = result.v0.z;
                }
              }
            }
          }
        }
        if ( v5[24] != 1 )
          v114 = v114 == 0;
        if ( !v114 )
          break;
      }
      if ( v5[3] )
      {
        v126 = 0;
        LOBYTE(v172) = 0;
        v127 = 0;
        if ( v37 != 0.0 )
        {
          v128 = *(_QWORD *)&result.v1.x;
          while ( !UFG::RegionComponent::IsHitPoint(
                     *(UFG::RegionComponent **)(*(_QWORD *)v128 + 216i64),
                     (UFG::qVector3 *)&result.v2) )
          {
            ++v127;
            v128 += 8i64;
            if ( v127 >= LODWORD(v37) )
            {
              v126 = (char)v172;
              goto LABEL_232;
            }
          }
          v126 = 1;
        }
LABEL_232:
        if ( v5[3] != 1 )
          v126 = v126 == 0;
        if ( !v126 )
          break;
      }
      LODWORD(v10) = 0;
LABEL_236:
      *(_QWORD *)&result.v1.z = --v53;
      if ( v53 < 0 )
        goto LABEL_237;
    }
    LODWORD(v10) = 0;
LABEL_94:
    v55 = v12 - 1;
    v11[v53] = v11[v55];
    if ( v12 <= 1 )
      LODWORD(v55) = v10;
    v12 = v55;
    goto LABEL_236;
  }
LABEL_237:
  v129 = (SSList *)AMemory::c_malloc_func(0x18ui64, "SSList");
  v130 = v129;
  v172 = (UFG::Camera *)v129;
  if ( v129 )
  {
    v129->i_items.i_count = 0;
    v129->i_items.i_array_p = 0i64;
    v129->i_items.i_size = 0;
    v129->i_items.i_array_p = (SSInstance **)AMemory::c_malloc_func(0i64, "APArrayBase.buffer");
  }
  else
  {
    v130 = 0i64;
  }
  for ( i = (signed int)(v12 - 1); i >= 0; --i )
  {
    v132 = v11[i].mNext;
    if ( v132 )
      v133 = (UFG::TSActorComponent *)v132[13].mNext[8].mNext;
    else
      v133 = 0i64;
    v134 = UFG::TSActorComponent::GetActor(v133);
    v135 = v130->i_items.i_count;
    if ( v130->i_items.i_size < (unsigned int)(v135 + 1) )
    {
      v136 = v130->i_items.i_array_p;
      if ( (_DWORD)v135 == -1 )
        LODWORD(v137) = 0;
      else
        v137 = (unsigned __int64)AMemory::c_req_byte_size_func(32 * (((unsigned int)v135 >> 2) + 1)) >> 3;
      v130->i_items.i_size = v137;
      v138 = APArrayBase<SSActor>::alloc_array(v137);
      v130->i_items.i_array_p = (SSInstance **)v138;
      memmove(v138, v136, 8 * v135);
      AMemory::c_free_func(v136);
    }
    v130->i_items.i_array_p[v135] = (SSInstance *)&v134->vfptr;
    ++v130->i_items.i_count;
  }
  v139 = v130->i_items.i_count;
  if ( (_DWORD)v139 )
  {
    v140 = (ARefCountMix<SSInstance> **)v130->i_items.i_array_p;
    for ( j = (unsigned __int64)&v140[v139]; (unsigned __int64)v140 < j; ++v140 )
      UFG::PersistentData::MapFloat::Iterator::Next(*v140 + 4);
  }
  v142 = SSList::as_instance(v130);
  *v175 = v142;
  if ( *(_QWORD *)&result.v1.x )
    operator delete[](*(void **)&result.v1.x);
  *(_QWORD *)&result.v1.x = 0i64;
  *(_QWORD *)&result.v0.z = 0i64;
  if ( v11 )
    operator delete[](v11);
}

// File Line: 981
// RVA: 0x506AD0
void __fastcall UFG::TSCharacterSearch::Mthd_search(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // r8
  SSInstance **v3; // rbp
  UFG::TSCharacterSearch *v4; // rsi
  SSActor *v5; // rbx
  SSClass *v6; // rdi

  v2 = pScope->i_scope_p.i_obj_p;
  v3 = ppResult;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v4 = (UFG::TSCharacterSearch *)v2[2].vfptr;
  v5 = (SSActor *)(*pScope->i_data.i_array_p)->i_data_p;
  if ( !v5 )
    goto LABEL_9;
  v6 = v5->i_class_p;
  if ( !v6->vfptr->is_actor_class((SSClassDescBase *)&v6->vfptr) )
  {
    if ( v6 == SSBrain::c_symbol_class_p && LODWORD(v5->i_user_data) != -1 )
    {
      v5 = SSActor::find((ASymbol *)&v5->i_user_data);
      goto LABEL_10;
    }
LABEL_9:
    v5 = 0i64;
  }
LABEL_10:
  UFG::TSCharacterSearch::DoSearch(v4, (UFG::TSCharacter *)v5, 0i64, v3);
}

// File Line: 991
// RVA: 0x5062E0
void __fastcall UFG::TSCharacterSearch::Mthd_refine_search(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // r8
  SSInstance **v3; // r14
  SSInvokedMethod *v4; // rdi
  UFG::TSCharacterSearch *v5; // rbp
  SSActor *v6; // rbx
  SSClass *v7; // rsi

  v2 = pScope->i_scope_p.i_obj_p;
  v3 = ppResult;
  v4 = pScope;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v5 = (UFG::TSCharacterSearch *)v2[2].vfptr;
  v6 = (SSActor *)(*pScope->i_data.i_array_p)->i_data_p;
  if ( !v6 )
    goto LABEL_9;
  v7 = v6->i_class_p;
  if ( !v7->vfptr->is_actor_class((SSClassDescBase *)&v7->vfptr) )
  {
    if ( v7 == SSBrain::c_symbol_class_p && LODWORD(v6->i_user_data) != -1 )
    {
      v6 = SSActor::find((ASymbol *)&v6->i_user_data);
      goto LABEL_10;
    }
LABEL_9:
    v6 = 0i64;
  }
LABEL_10:
  UFG::TSCharacterSearch::DoSearch(
    v5,
    (UFG::TSCharacter *)v6,
    *(SSList **)(*(_QWORD *)(*((_QWORD *)v4->i_data.i_array_p + 1) + 8i64) + 32i64),
    v3);
}

// File Line: 1005
// RVA: 0x4D24E0
void UFG::TSCharacterSearch::BindAtomics(void)
{
  UFG::TSCharacterSearch::mspCharacterSearchClass = SSBrain::get_class("CharacterSearch");
  SSClass::register_method_func(
    UFG::TSCharacterSearch::mspCharacterSearchClass,
    &ASymbolX_ctor,
    UFG::TSCharacterSearch::Mthd_constructor,
    0);
  SSClass::register_method_func(
    UFG::TSCharacterSearch::mspCharacterSearchClass,
    &ASymbolX_dtor,
    UFG::TSCharacterSearch::Mthd_destructor,
    0);
  SSClass::register_method_func(
    UFG::TSCharacterSearch::mspCharacterSearchClass,
    "set_radius",
    UFG::TSCharacterSearch::Mthd_set_radius,
    0);
  SSClass::register_method_func(
    UFG::TSCharacterSearch::mspCharacterSearchClass,
    "alive_exclude",
    UFG::TSCharacterSearch::Mthd_alive_exclude,
    0);
  SSClass::register_method_func(
    UFG::TSCharacterSearch::mspCharacterSearchClass,
    "alive_include",
    UFG::TSCharacterSearch::Mthd_alive_include,
    0);
  SSClass::register_method_func(
    UFG::TSCharacterSearch::mspCharacterSearchClass,
    "faction_exclude",
    UFG::TSCharacterSearch::Mthd_faction_exclude,
    0);
  SSClass::register_method_func(
    UFG::TSCharacterSearch::mspCharacterSearchClass,
    "faction_include",
    UFG::TSCharacterSearch::Mthd_faction_include,
    0);
  SSClass::register_method_func(
    UFG::TSCharacterSearch::mspCharacterSearchClass,
    "gender_exclude",
    UFG::TSCharacterSearch::Mthd_gender_exclude,
    0);
  SSClass::register_method_func(
    UFG::TSCharacterSearch::mspCharacterSearchClass,
    "gender_include",
    UFG::TSCharacterSearch::Mthd_gender_include,
    0);
  SSClass::register_method_func(
    UFG::TSCharacterSearch::mspCharacterSearchClass,
    "indoors_exclude",
    UFG::TSCharacterSearch::Mthd_indoors_exclude,
    0);
  SSClass::register_method_func(
    UFG::TSCharacterSearch::mspCharacterSearchClass,
    "indoors_include",
    UFG::TSCharacterSearch::Mthd_indoors_include,
    0);
  SSClass::register_method_func(
    UFG::TSCharacterSearch::mspCharacterSearchClass,
    "invehicle_exclude",
    UFG::TSCharacterSearch::Mthd_invehicle_exclude,
    0);
  SSClass::register_method_func(
    UFG::TSCharacterSearch::mspCharacterSearchClass,
    "invehicle_include",
    UFG::TSCharacterSearch::Mthd_invehicle_include,
    0);
  SSClass::register_method_func(
    UFG::TSCharacterSearch::mspCharacterSearchClass,
    "objective_exclude",
    UFG::TSCharacterSearch::Mthd_objective_exclude,
    0);
  SSClass::register_method_func(
    UFG::TSCharacterSearch::mspCharacterSearchClass,
    "objective_include",
    UFG::TSCharacterSearch::Mthd_objective_include,
    0);
  SSClass::register_method_func(
    UFG::TSCharacterSearch::mspCharacterSearchClass,
    "spawnpriority_exclude",
    UFG::TSCharacterSearch::Mthd_spawnpriority_exclude,
    0);
  SSClass::register_method_func(
    UFG::TSCharacterSearch::mspCharacterSearchClass,
    "spawnpriority_include",
    UFG::TSCharacterSearch::Mthd_spawnpriority_include,
    0);
  SSClass::register_method_func(
    UFG::TSCharacterSearch::mspCharacterSearchClass,
    "equiped_item_exclude",
    UFG::TSCharacterSearch::Mthd_equiped_item_exclude,
    0);
  SSClass::register_method_func(
    UFG::TSCharacterSearch::mspCharacterSearchClass,
    "equiped_item_include",
    UFG::TSCharacterSearch::Mthd_equiped_item_include,
    0);
  SSClass::register_method_func(
    UFG::TSCharacterSearch::mspCharacterSearchClass,
    "scenariocontrol_exclude",
    UFG::TSCharacterSearch::Mthd_scenariocontrol_exclude,
    0);
  SSClass::register_method_func(
    UFG::TSCharacterSearch::mspCharacterSearchClass,
    "scenariocontrol_include",
    UFG::TSCharacterSearch::Mthd_scenariocontrol_include,
    0);
  SSClass::register_method_func(
    UFG::TSCharacterSearch::mspCharacterSearchClass,
    "inview_exclude",
    UFG::TSCharacterSearch::Mthd_alive_exclude,
    0);
  SSClass::register_method_func(
    UFG::TSCharacterSearch::mspCharacterSearchClass,
    "inview_include",
    UFG::TSCharacterSearch::Mthd_alive_include,
    0);
  SSClass::register_method_func(
    UFG::TSCharacterSearch::mspCharacterSearchClass,
    "character_type_exclude",
    UFG::TSCharacterSearch::Mthd_character_type_exclude,
    0);
  SSClass::register_method_func(
    UFG::TSCharacterSearch::mspCharacterSearchClass,
    "character_type_include",
    UFG::TSCharacterSearch::Mthd_character_type_include,
    0);
  SSClass::register_method_func(
    UFG::TSCharacterSearch::mspCharacterSearchClass,
    "using_poi_exclude",
    UFG::TSCharacterSearch::Mthd_using_poi_exclude,
    0);
  SSClass::register_method_func(
    UFG::TSCharacterSearch::mspCharacterSearchClass,
    "using_poi_include",
    UFG::TSCharacterSearch::Mthd_using_poi_include,
    0);
  SSClass::register_method_func(
    UFG::TSCharacterSearch::mspCharacterSearchClass,
    "search",
    UFG::TSCharacterSearch::Mthd_search,
    0);
  SSClass::register_method_func(
    UFG::TSCharacterSearch::mspCharacterSearchClass,
    "refine_search",
    UFG::TSCharacterSearch::Mthd_refine_search,
    0);
}

