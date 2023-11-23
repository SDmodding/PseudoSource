// File Line: 187
// RVA: 0x4CBF80
void __fastcall UFG::TSCharacterSearch::~TSCharacterSearch(UFG::TSCharacterSearch *this)
{
  UFG::qSymbol *p; // rcx
  UFG::qSymbol *v3; // rbx
  UFG::eAIObjective *v4; // rcx
  UFG::qSymbol *v5; // rcx
  UFG::qSymbol *v6; // rbx

  p = this->mCharacterTypes.p;
  if ( p )
  {
    v3 = p - 1;
    `eh vector destructor iterator(p, 4ui64, p[-1].mUID, (void (__fastcall *)(void *))_);
    operator delete[](v3);
  }
  this->mCharacterTypes.p = 0i64;
  *(_QWORD *)&this->mCharacterTypes.size = 0i64;
  v4 = this->mObjectives.p;
  if ( v4 )
    operator delete[](v4);
  this->mObjectives.p = 0i64;
  *(_QWORD *)&this->mObjectives.size = 0i64;
  v5 = this->mFactions.p;
  if ( v5 )
  {
    v6 = v5 - 1;
    `eh vector destructor iterator(v5, 4ui64, v5[-1].mUID, (void (__fastcall *)(void *))_);
    operator delete[](v6);
  }
  this->mFactions.p = 0i64;
  *(_QWORD *)&this->mFactions.size = 0i64;
}

// File Line: 191
// RVA: 0x4F69D0
void __fastcall UFG::TSCharacterSearch::Mthd_constructor(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::allocator::free_link *v3; // rax
  UFG::allocator::free_link *v4; // rdx
  SSObjectBase *i_obj_p; // rcx

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
  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( i_obj_p && pScope->i_scope_p.i_ptr_id == i_obj_p->i_ptr_id )
    i_obj_p[2].vfptr = (SSObjectBaseVtbl *)v4;
  else
    *(_QWORD *)&MEMORY[0x20] = v4;
}

// File Line: 199
// RVA: 0x4F7E10
void __fastcall UFG::TSCharacterSearch::Mthd_destructor(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rdx
  SSObjectBaseVtbl *vfptr; // rbx

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  vfptr = i_obj_p[2].vfptr;
  if ( vfptr )
  {
    UFG::TSCharacterSearch::~TSCharacterSearch((UFG::TSCharacterSearch *)i_obj_p[2].vfptr);
    operator delete[](vfptr);
  }
}

// File Line: 206
// RVA: 0x4F4790
void __fastcall UFG::TSCharacterSearch::Mthd_alive_exclude(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rdx

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( i_obj_p && pScope->i_scope_p.i_ptr_id == i_obj_p->i_ptr_id )
    LODWORD(i_obj_p[2].vfptr->get_obj_type) = 2;
  else
    *(_DWORD *)(*(_QWORD *)&MEMORY[0x20] + 8i64) = 2;
}

// File Line: 213
// RVA: 0x4F47C0
void __fastcall UFG::TSCharacterSearch::Mthd_alive_include(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rdx

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( i_obj_p && pScope->i_scope_p.i_ptr_id == i_obj_p->i_ptr_id )
    LODWORD(i_obj_p[2].vfptr->get_obj_type) = 1;
  else
    *(_DWORD *)(*(_QWORD *)&MEMORY[0x20] + 8i64) = 1;
}

// File Line: 220
// RVA: 0x4F9C40
void __fastcall UFG::TSCharacterSearch::Mthd_faction_exclude(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rbx
  SSObjectBaseVtbl *vfptr; // rbx

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  vfptr = i_obj_p[2].vfptr;
  UFG::qArray<UFG::qSymbol,0>::Add(
    (UFG::qArray<UFG::qSymbol,0> *)&vfptr->get_topmost_scope,
    (UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data,
    "qArray.Add");
  LODWORD(vfptr->get_scope_context) = 2;
}

// File Line: 232
// RVA: 0x4F9D20
void __fastcall UFG::TSCharacterSearch::Mthd_faction_include(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rbx
  SSObjectBaseVtbl *vfptr; // rbx

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  vfptr = i_obj_p[2].vfptr;
  UFG::qArray<UFG::qSymbol,0>::Add(
    (UFG::qArray<UFG::qSymbol,0> *)&vfptr->get_topmost_scope,
    (UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data,
    "qArray.Add");
  LODWORD(vfptr->get_scope_context) = 1;
}

// File Line: 244
// RVA: 0x4FACF0
void __fastcall UFG::TSCharacterSearch::Mthd_gender_exclude(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r8
  int v3; // r9d

  i_obj_p = pScope->i_scope_p.i_obj_p;
  v3 = 0;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  LOBYTE(v3) = LODWORD((*pScope->i_data.i_array_p)->i_data_p->i_user_data) == qSymbol_Male.mUID;
  HIDWORD(i_obj_p[2].vfptr->__vecDelDtor) = v3 + 1;
}

// File Line: 262
// RVA: 0x4FAD30
void __fastcall UFG::TSCharacterSearch::Mthd_gender_include(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r8
  int v3; // r9d

  i_obj_p = pScope->i_scope_p.i_obj_p;
  v3 = 0;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  LOBYTE(v3) = LODWORD((*pScope->i_data.i_array_p)->i_data_p->i_user_data) != qSymbol_Male.mUID;
  HIDWORD(i_obj_p[2].vfptr->__vecDelDtor) = v3 + 1;
}

// File Line: 280
// RVA: 0x500360
void __fastcall UFG::TSCharacterSearch::Mthd_indoors_exclude(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rdx

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( i_obj_p && pScope->i_scope_p.i_ptr_id == i_obj_p->i_ptr_id )
    HIDWORD(i_obj_p[2].vfptr->get_obj_type) = 2;
  else
    *(_DWORD *)(*(_QWORD *)&MEMORY[0x20] + 12i64) = 2;
}

// File Line: 287
// RVA: 0x500390
void __fastcall UFG::TSCharacterSearch::Mthd_indoors_include(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rdx

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( i_obj_p && pScope->i_scope_p.i_ptr_id == i_obj_p->i_ptr_id )
    HIDWORD(i_obj_p[2].vfptr->get_obj_type) = 1;
  else
    *(_DWORD *)(*(_QWORD *)&MEMORY[0x20] + 12i64) = 1;
}

// File Line: 294
// RVA: 0x5003C0
void __fastcall UFG::TSCharacterSearch::Mthd_invehicle_exclude(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rdx

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( i_obj_p && pScope->i_scope_p.i_ptr_id == i_obj_p->i_ptr_id )
    LODWORD(i_obj_p[2].vfptr->is_actor) = 2;
  else
    *(_DWORD *)(*(_QWORD *)&MEMORY[0x20] + 16i64) = 2;
}

// File Line: 301
// RVA: 0x5003F0
void __fastcall UFG::TSCharacterSearch::Mthd_invehicle_include(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rdx

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( i_obj_p && pScope->i_scope_p.i_ptr_id == i_obj_p->i_ptr_id )
    LODWORD(i_obj_p[2].vfptr->is_actor) = 1;
  else
    *(_DWORD *)(*(_QWORD *)&MEMORY[0x20] + 16i64) = 1;
}

// File Line: 308
// RVA: 0x505080
void __fastcall UFG::TSCharacterSearch::Mthd_objective_exclude(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rsi
  unsigned int v3; // ebp
  SSObjectBaseVtbl *vfptr; // rsi
  unsigned int v5; // edi
  const char **v6; // rbx
  SSInstance *i_data_p; // r14
  unsigned int is_actor_high; // ebx
  __int64 is_actor_low; // r13
  unsigned int v10; // r14d
  unsigned int v11; // ebx
  unsigned __int64 v12; // rax
  UFG::allocator::free_link *v13; // rax
  UFG::allocator::free_link *v14; // r15
  __int64 v15; // rcx
  SSInstance *(__fastcall *as_instance)(SSObjectBase *); // rax

  i_obj_p = pScope->i_scope_p.i_obj_p;
  v3 = 0;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  vfptr = i_obj_p[2].vfptr;
  v5 = 0;
  v6 = UFG::AIObjectiveNames;
  i_data_p = (*pScope->i_data.i_array_p)->i_data_p;
  while ( (unsigned int)UFG::qStringCompareInsensitive(*(const char **)i_data_p->i_user_data, *v6, -1) )
  {
    ++v5;
    ++v6;
    if ( v5 >= 0x24 )
      return;
  }
  if ( ((__int64)vfptr[1].get_obj_type & 0xFFFFFFFD) == 0 )
  {
    is_actor_high = HIDWORD(vfptr[1].is_actor);
    is_actor_low = LODWORD(vfptr[1].is_actor);
    v10 = is_actor_low + 1;
    if ( (int)is_actor_low + 1 > is_actor_high )
    {
      if ( is_actor_high )
        v11 = 2 * is_actor_high;
      else
        v11 = 1;
      for ( ; v11 < v10; v11 *= 2 )
        ;
      if ( v11 <= 4 )
        v11 = 4;
      if ( v11 - v10 > 0x10000 )
        v11 = is_actor_low + 65537;
      if ( v11 != (_DWORD)is_actor_low )
      {
        v12 = 4i64 * v11;
        if ( !is_mul_ok(v11, 4ui64) )
          v12 = -1i64;
        v13 = UFG::qMalloc(v12, "qArray.Add", 0i64);
        v14 = v13;
        if ( vfptr[1].as_instance )
        {
          if ( LODWORD(vfptr[1].is_actor) )
          {
            do
            {
              v15 = v3++;
              *((_DWORD *)&v13->mNext + v15) = *((_DWORD *)vfptr[1].as_instance + v15);
            }
            while ( v3 < LODWORD(vfptr[1].is_actor) );
          }
          operator delete[](vfptr[1].as_instance);
        }
        vfptr[1].as_instance = (SSInstance *(__fastcall *)(SSObjectBase *))v14;
        HIDWORD(vfptr[1].is_actor) = v11;
      }
    }
    as_instance = vfptr[1].as_instance;
    LODWORD(vfptr[1].is_actor) = v10;
    *((_DWORD *)as_instance + is_actor_low) = v5;
    LODWORD(vfptr[1].get_obj_type) = 2;
  }
}

// File Line: 339
// RVA: 0x5051F0
void __fastcall UFG::TSCharacterSearch::Mthd_objective_include(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rsi
  unsigned int v3; // ebp
  SSObjectBaseVtbl *vfptr; // rsi
  unsigned int v5; // edi
  const char **v6; // rbx
  SSInstance *i_data_p; // r14
  unsigned int is_actor_high; // ebx
  __int64 is_actor_low; // r13
  unsigned int v10; // r14d
  unsigned int v11; // ebx
  unsigned __int64 v12; // rax
  UFG::allocator::free_link *v13; // rax
  UFG::allocator::free_link *v14; // r15
  __int64 v15; // rcx
  SSInstance *(__fastcall *as_instance)(SSObjectBase *); // rax

  i_obj_p = pScope->i_scope_p.i_obj_p;
  v3 = 0;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  vfptr = i_obj_p[2].vfptr;
  v5 = 0;
  v6 = UFG::AIObjectiveNames;
  i_data_p = (*pScope->i_data.i_array_p)->i_data_p;
  while ( (unsigned int)UFG::qStringCompareInsensitive(*(const char **)i_data_p->i_user_data, *v6, -1) )
  {
    ++v5;
    ++v6;
    if ( v5 >= 0x24 )
      return;
  }
  if ( LODWORD(vfptr[1].get_obj_type) <= 1 )
  {
    is_actor_high = HIDWORD(vfptr[1].is_actor);
    is_actor_low = LODWORD(vfptr[1].is_actor);
    v10 = is_actor_low + 1;
    if ( (int)is_actor_low + 1 > is_actor_high )
    {
      if ( is_actor_high )
        v11 = 2 * is_actor_high;
      else
        v11 = 1;
      for ( ; v11 < v10; v11 *= 2 )
        ;
      if ( v11 <= 4 )
        v11 = 4;
      if ( v11 - v10 > 0x10000 )
        v11 = is_actor_low + 65537;
      if ( v11 != (_DWORD)is_actor_low )
      {
        v12 = 4i64 * v11;
        if ( !is_mul_ok(v11, 4ui64) )
          v12 = -1i64;
        v13 = UFG::qMalloc(v12, "qArray.Add", 0i64);
        v14 = v13;
        if ( vfptr[1].as_instance )
        {
          if ( LODWORD(vfptr[1].is_actor) )
          {
            do
            {
              v15 = v3++;
              *((_DWORD *)&v13->mNext + v15) = *((_DWORD *)vfptr[1].as_instance + v15);
            }
            while ( v3 < LODWORD(vfptr[1].is_actor) );
          }
          operator delete[](vfptr[1].as_instance);
        }
        vfptr[1].as_instance = (SSInstance *(__fastcall *)(SSObjectBase *))v14;
        HIDWORD(vfptr[1].is_actor) = v11;
      }
    }
    as_instance = vfptr[1].as_instance;
    LODWORD(vfptr[1].is_actor) = v10;
    *((_DWORD *)as_instance + is_actor_low) = v5;
    LODWORD(vfptr[1].get_obj_type) = 1;
  }
}

// File Line: 370
// RVA: 0x506A70
void __fastcall UFG::TSCharacterSearch::Mthd_scenariocontrol_exclude(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rdx

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( i_obj_p && pScope->i_scope_p.i_ptr_id == i_obj_p->i_ptr_id )
    HIDWORD(i_obj_p[2].vfptr->is_actor) = 2;
  else
    *(_DWORD *)(*(_QWORD *)&MEMORY[0x20] + 20i64) = 2;
}

// File Line: 377
// RVA: 0x506AA0
void __fastcall UFG::TSCharacterSearch::Mthd_scenariocontrol_include(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rdx

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( i_obj_p && pScope->i_scope_p.i_ptr_id == i_obj_p->i_ptr_id )
    HIDWORD(i_obj_p[2].vfptr->is_actor) = 1;
  else
    *(_DWORD *)(*(_QWORD *)&MEMORY[0x20] + 20i64) = 1;
}

// File Line: 384
// RVA: 0x50E490
void __fastcall UFG::TSCharacterSearch::Mthd_using_poi_exclude(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rdx

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( i_obj_p && pScope->i_scope_p.i_ptr_id == i_obj_p->i_ptr_id )
    HIDWORD(i_obj_p[2].vfptr->as_instance) = 2;
  else
    *(_DWORD *)(*(_QWORD *)&MEMORY[0x20] + 28i64) = 2;
}

// File Line: 391
// RVA: 0x50E4C0
void __fastcall UFG::TSCharacterSearch::Mthd_using_poi_include(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rdx

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( i_obj_p && pScope->i_scope_p.i_ptr_id == i_obj_p->i_ptr_id )
    HIDWORD(i_obj_p[2].vfptr->as_instance) = 1;
  else
    *(_DWORD *)(*(_QWORD *)&MEMORY[0x20] + 28i64) = 1;
}

// File Line: 399
// RVA: 0x50B670
void __fastcall UFG::TSCharacterSearch::Mthd_spawnpriority_exclude(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rdx
  SSObjectBaseVtbl *vfptr; // rdx

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  vfptr = i_obj_p[2].vfptr;
  HIDWORD(vfptr->get_data_by_name) = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  LODWORD(vfptr->get_data_by_name) = 2;
}

// File Line: 409
// RVA: 0x50B6A0
void __fastcall UFG::TSCharacterSearch::Mthd_spawnpriority_include(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rdx
  SSObjectBaseVtbl *vfptr; // rdx

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  vfptr = i_obj_p[2].vfptr;
  HIDWORD(vfptr->get_data_by_name) = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  LODWORD(vfptr->get_data_by_name) = 1;
}

// File Line: 419
// RVA: 0x50A2A0
void __fastcall UFG::TSCharacterSearch::Mthd_set_radius(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rdx

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  LODWORD(i_obj_p[2].vfptr->__vecDelDtor) = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
}

// File Line: 442
// RVA: 0x4F9460
void __fastcall UFG::TSCharacterSearch::Mthd_equiped_item_exclude(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rbx
  SSObjectBaseVtbl *vfptr; // rbx
  SSInstance *i_data_p; // rdx

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  vfptr = i_obj_p[2].vfptr;
  i_data_p = (*pScope->i_data.i_array_p)->i_data_p;
  LODWORD(vfptr->set_data_by_name) = 2;
  HIDWORD(vfptr->set_data_by_name) = TracksEnum<unsigned long>::GetEnumFromSymbol(
                                       &UFG::gInventoryItemTracksEnum,
                                       (UFG::qSymbol *)&i_data_p->i_user_data);
}

// File Line: 452
// RVA: 0x4F94B0
void __fastcall UFG::TSCharacterSearch::Mthd_equiped_item_include(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rbx
  SSObjectBaseVtbl *vfptr; // rbx
  SSInstance *i_data_p; // rdx

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  vfptr = i_obj_p[2].vfptr;
  i_data_p = (*pScope->i_data.i_array_p)->i_data_p;
  LODWORD(vfptr->set_data_by_name) = 1;
  HIDWORD(vfptr->set_data_by_name) = TracksEnum<unsigned long>::GetEnumFromSymbol(
                                       &UFG::gInventoryItemTracksEnum,
                                       (UFG::qSymbol *)&i_data_p->i_user_data);
}

// File Line: 462
// RVA: 0x4F6210
void __fastcall UFG::TSCharacterSearch::Mthd_character_type_exclude(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rdx
  SSObjectBaseVtbl *vfptr; // rbp
  SSData **i_array_p; // rdx
  unsigned int *i_user_data; // r8
  SSInstance *i_data_p; // rcx
  unsigned int i_class_p; // eax
  __int64 *v8; // r14
  __int64 v9; // r12
  __int64 set_data_by_name_low; // r15
  unsigned int set_data_by_name_high; // edx
  __int64 v12; // rsi
  unsigned int v13; // ebx
  unsigned int v14; // edx
  SSInvokedContextBase *(__fastcall *get_scope_context)(SSObjectBase *); // rcx

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  vfptr = i_obj_p[2].vfptr;
  i_array_p = pScope->i_data.i_array_p;
  i_user_data = (unsigned int *)(*i_array_p)->i_data_p->i_user_data;
  i_data_p = i_array_p[1]->i_data_p;
  if ( i_data_p )
    i_class_p = (unsigned int)i_data_p[1].i_class_p;
  else
    i_class_p = UFG::gNullQSymbol.mUID;
  LODWORD(vfptr[1].get_topmost_scope) = i_class_p;
  v8 = (__int64 *)*((_QWORD *)i_user_data + 1);
  if ( *i_user_data )
  {
    v9 = *i_user_data;
    do
    {
      set_data_by_name_low = LODWORD(vfptr[1].set_data_by_name);
      set_data_by_name_high = HIDWORD(vfptr[1].set_data_by_name);
      v12 = *v8;
      v13 = set_data_by_name_low + 1;
      if ( (int)set_data_by_name_low + 1 > set_data_by_name_high )
      {
        if ( set_data_by_name_high )
          v14 = 2 * set_data_by_name_high;
        else
          v14 = 1;
        for ( ; v14 < v13; v14 *= 2 )
          ;
        if ( v14 <= 4 )
          v14 = 4;
        if ( v14 - v13 > 0x10000 )
          v14 = set_data_by_name_low + 65537;
        UFG::qArray<UFG::qSymbol,0>::Reallocate(
          (UFG::qArray<UFG::qSymbol,0> *)&vfptr[1].set_data_by_name,
          v14,
          "qArray.Add");
      }
      get_scope_context = vfptr[1].get_scope_context;
      LODWORD(vfptr[1].set_data_by_name) = v13;
      ++v8;
      *((_DWORD *)get_scope_context + set_data_by_name_low) = *(_DWORD *)(v12 + 32);
      --v9;
    }
    while ( v9 );
  }
  LODWORD(vfptr[1].get_data_by_name) = 2;
}

// File Line: 493
// RVA: 0x4F6330
void __fastcall UFG::TSCharacterSearch::Mthd_character_type_include(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rdx
  SSObjectBaseVtbl *vfptr; // rbp
  SSData **i_array_p; // rdx
  unsigned int *i_user_data; // r8
  SSInstance *i_data_p; // rcx
  unsigned int i_class_p; // eax
  __int64 *v8; // r14
  __int64 v9; // r12
  __int64 set_data_by_name_low; // r15
  unsigned int set_data_by_name_high; // edx
  __int64 v12; // rsi
  unsigned int v13; // ebx
  unsigned int v14; // edx
  SSInvokedContextBase *(__fastcall *get_scope_context)(SSObjectBase *); // rcx

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  vfptr = i_obj_p[2].vfptr;
  i_array_p = pScope->i_data.i_array_p;
  i_user_data = (unsigned int *)(*i_array_p)->i_data_p->i_user_data;
  i_data_p = i_array_p[1]->i_data_p;
  if ( i_data_p )
    i_class_p = (unsigned int)i_data_p[1].i_class_p;
  else
    i_class_p = UFG::gNullQSymbol.mUID;
  LODWORD(vfptr[1].get_topmost_scope) = i_class_p;
  v8 = (__int64 *)*((_QWORD *)i_user_data + 1);
  if ( *i_user_data )
  {
    v9 = *i_user_data;
    do
    {
      set_data_by_name_low = LODWORD(vfptr[1].set_data_by_name);
      set_data_by_name_high = HIDWORD(vfptr[1].set_data_by_name);
      v12 = *v8;
      v13 = set_data_by_name_low + 1;
      if ( (int)set_data_by_name_low + 1 > set_data_by_name_high )
      {
        if ( set_data_by_name_high )
          v14 = 2 * set_data_by_name_high;
        else
          v14 = 1;
        for ( ; v14 < v13; v14 *= 2 )
          ;
        if ( v14 <= 4 )
          v14 = 4;
        if ( v14 - v13 > 0x10000 )
          v14 = set_data_by_name_low + 65537;
        UFG::qArray<UFG::qSymbol,0>::Reallocate(
          (UFG::qArray<UFG::qSymbol,0> *)&vfptr[1].set_data_by_name,
          v14,
          "qArray.Add");
      }
      get_scope_context = vfptr[1].get_scope_context;
      LODWORD(vfptr[1].set_data_by_name) = v13;
      ++v8;
      *((_DWORD *)get_scope_context + set_data_by_name_low) = *(_DWORD *)(v12 + 32);
      --v9;
    }
    while ( v9 );
  }
  LODWORD(vfptr[1].get_data_by_name) = 1;
}

// File Line: 525
// RVA: 0x4DF510
void __fastcall UFG::TSCharacterSearch::DoSearch(
        UFG::Camera *search,
        UFG::TSCharacter *_searchCharacter,
        SSList *previousList,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // r13
  UFG::TransformNodeComponent *m_pComponent; // rbx
  float y; // xmm1_4
  float z; // xmm2_4
  __int64 v10; // rbx
  UFG::allocator::free_link *v11; // rsi
  unsigned int v12; // edi
  unsigned int v13; // r15d
  __int64 v14; // r14
  __int64 i_count; // rdx
  __int64 v16; // r12
  unsigned int v17; // ecx
  unsigned int v18; // r13d
  unsigned int v19; // ebx
  unsigned __int64 v20; // rax
  UFG::allocator::free_link *v21; // rax
  UFG::allocator::free_link *v22; // r15
  UFG::allocator::free_link *v23; // rcx
  __int64 v24; // rdx
  float v25; // xmm6_4
  UFG::qNode<UFG::SimObjectCharacterPropertiesComponent,UFG::SimObjectCharacterPropertiesComponent> *v26; // r12
  UFG::qNode<UFG::SimObjectCharacterPropertiesComponent,UFG::SimObjectCharacterPropertiesComponent> *mNext; // rbx
  UFG::TransformNodeComponent *v28; // rbx
  unsigned int v29; // ecx
  unsigned int v30; // r13d
  unsigned int v31; // ebx
  unsigned __int64 v32; // rax
  UFG::allocator::free_link *v33; // rax
  UFG::allocator::free_link *v34; // r15
  UFG::allocator::free_link *v35; // rcx
  __int64 v36; // rdx
  float v37; // r13d
  __int64 size; // r15
  unsigned __int64 v39; // rax
  UFG::allocator::free_link *v40; // rax
  unsigned int v41; // r12d
  UFG::allocator::free_link *v42; // r14
  unsigned int v43; // edx
  UFG::qBaseTreeRB *v44; // rax
  float v45; // ecx
  float v46; // r15d
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
  UFG::eAIObjective m_CurrentObjective; // r9d
  unsigned int v58; // ecx
  unsigned int x_low; // edx
  UFG::SimObjectCharacterPropertiesComponent *v60; // rax
  bool v61; // zf
  UFG::SimObjectCharacterPropertiesComponent *v62; // rax
  unsigned int v63; // ecx
  unsigned int v64; // edx
  UFG::TSCharacterSearch::ALIVE v65; // eax
  bool IsKnockedOut; // al
  bool v67; // cl
  UFG::BaseCameraComponent *mCurrentCamera; // rcx
  UFG::Camera *p_mCamera; // rax
  UFG::qMatrix44 *ViewProjection; // rbx
  UFG::qMatrix44 *WorldView; // rax
  float v72; // xmm8_4
  float v73; // xmm9_4
  float v74; // xmm10_4
  float v75; // xmm11_4
  float v76; // xmm12_4
  float v77; // xmm14_4
  float v78; // xmm15_4
  float v79; // xmm0_4
  float v80; // xmm0_4
  float v81; // xmm0_4
  __m128 v82; // xmm2
  float v83; // xmm0_4
  __m128 v84; // xmm5
  __m128 v85; // xmm2
  float v86; // xmm4_4
  float v87; // xmm0_4
  __m128 v88; // xmm2
  float v89; // xmm3_4
  UFG::TransformNodeComponent *v90; // rbx
  UFG::TSCharacterSearch::INVEHICLE mMotionBlurTimeLimit; // ecx
  UFG::SimComponent *v92; // rax
  bool v93; // al
  unsigned int mUID; // eax
  UFG::StreamedResourceComponent *v95; // rcx
  bool v96; // al
  bool v97; // bl
  UFG::SimComponent *v98; // r8
  UFG::SimObject *v99; // rcx
  UFG::SimComponent *ComponentOfType; // rax
  int m_pSimObject; // eax
  bool v102; // dl
  UFG::SimComponent *v103; // r8
  UFG::SimObject *v104; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *v106; // rax
  bool *v107; // rax
  bool v108; // al
  UFG::TSCharacterSearch::SCENARIOCONTROL mMotionBlurTimeLimit_high; // ecx
  bool v110; // bl
  UFG::SceneObjectProperties *m_pSceneObj; // rax
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::qPropertySet *v113; // rax
  char *MemImagePtr; // rax
  __int64 v115; // rcx
  UFG::qPropertyList *v116; // rcx
  unsigned int mNumElements; // r15d
  UFG::qSymbol *v118; // r11
  unsigned int v119; // r10d
  unsigned int z_low; // edx
  int v121; // ecx
  char v122; // al
  unsigned int v123; // ebx
  __int64 v124; // r15
  SSList *v125; // rax
  SSList *v126; // rbx
  __int64 i; // r14
  UFG::allocator::free_link *v128; // rax
  UFG::TSActorComponent *v129; // rcx
  UFG::TSActor *Actor; // r12
  __int64 v131; // rdi
  SSInstance **i_array_p; // r15
  unsigned __int64 v133; // rax
  SSActor **v134; // rax
  __int64 v135; // rax
  ARefCountMix<SSInstance> **v136; // rdi
  ARefCountMix<SSInstance> **j; // r14
  SSInstance *v138; // rax
  unsigned int v139; // [rsp+20h] [rbp-A0h]
  UFG::allocator::free_link *v140; // [rsp+28h] [rbp-98h]
  __int64 v141; // [rsp+30h] [rbp-90h]
  __int64 v142; // [rsp+30h] [rbp-90h]
  float v143; // [rsp+3Ch] [rbp-84h]
  float v144; // [rsp+44h] [rbp-7Ch]
  UFG::SimObjectCVBase *v145; // [rsp+48h] [rbp-78h]
  UFG::qMatrix44 result; // [rsp+50h] [rbp-70h] BYREF
  UFG::qVector4 planes; // [rsp+90h] [rbp-30h] BYREF
  float v148; // [rsp+A0h] [rbp-20h]
  float v149; // [rsp+A4h] [rbp-1Ch]
  float v150; // [rsp+A8h] [rbp-18h]
  float v151; // [rsp+ACh] [rbp-14h]
  float v152; // [rsp+B0h] [rbp-10h]
  float v153; // [rsp+B4h] [rbp-Ch]
  float v154; // [rsp+B8h] [rbp-8h]
  float v155; // [rsp+BCh] [rbp-4h]
  float v156; // [rsp+C0h] [rbp+0h]
  float v157; // [rsp+C4h] [rbp+4h]
  float v158; // [rsp+C8h] [rbp+8h]
  float v159; // [rsp+CCh] [rbp+Ch]
  float v160; // [rsp+D0h] [rbp+10h]
  float v161; // [rsp+D4h] [rbp+14h]
  float v162; // [rsp+D8h] [rbp+18h]
  float v163; // [rsp+DCh] [rbp+1Ch]
  float v164; // [rsp+E0h] [rbp+20h]
  float v165; // [rsp+E4h] [rbp+24h]
  float v166; // [rsp+E8h] [rbp+28h]
  float v167; // [rsp+ECh] [rbp+2Ch]
  UFG::TransformNodeComponent *v168; // [rsp+F0h] [rbp+30h]
  __int64 v169; // [rsp+F8h] [rbp+38h]
  UFG::Camera *v170; // [rsp+1F0h] [rbp+130h]
  UFG::allocator::free_link *v171; // [rsp+1F8h] [rbp+138h]
  SSList *v172; // [rsp+200h] [rbp+140h]
  SSInstance **v173; // [rsp+208h] [rbp+148h]

  v169 = -2i64;
  m_pPointer = _searchCharacter->mpSimObj.m_pPointer;
  v145 = (UFG::SimObjectCVBase *)m_pPointer;
  if ( m_pPointer && (m_pPointer->m_Flags & 0x4000) != 0 )
  {
    m_pComponent = (UFG::TransformNodeComponent *)m_pPointer->m_Components.p[2].m_pComponent;
  }
  else
  {
    v145 = 0i64;
    m_pComponent = 0i64;
  }
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pComponent);
  y = m_pComponent->mWorldTransform.v3.y;
  z = m_pComponent->mWorldTransform.v3.z;
  result.v2.x = m_pComponent->mWorldTransform.v3.x;
  result.v2.y = y;
  result.v2.z = z;
  v10 = 0i64;
  v11 = 0i64;
  v140 = 0i64;
  v12 = 0;
  v139 = 0;
  v13 = 0;
  if ( previousList )
  {
    if ( previousList->i_items.i_count )
    {
      v14 = 0i64;
      i_count = previousList->i_items.i_count;
      v141 = i_count;
      do
      {
        v16 = *(_QWORD *)&previousList->i_items.i_array_p[v14][4].i_ref_count;
        if ( !v16 || (*(_WORD *)(v16 + 76) & 0x4000) == 0 )
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
            v140 = v22;
            v13 = v19;
            i_count = v141;
            v17 = v12;
            v10 = 0i64;
          }
        }
        ++v12;
        v139 = v18;
        v11[v17].mNext = (UFG::allocator::free_link *)v16;
        ++v14;
        v141 = --i_count;
        previousList = v172;
      }
      while ( i_count );
LABEL_60:
      search = v170;
    }
  }
  else
  {
    v25 = search->mFOVOffset * search->mFOVOffset;
    v26 = UFG::SimObjectCharacterPropertiesComponent::s_SimObjectCharacterPropertiesComponentList.mNode.mNext - 10;
    if ( (UFG::qList<UFG::SimObjectCharacterPropertiesComponent,UFG::SimObjectCharacterPropertiesComponent,1,0> *)&UFG::SimObjectCharacterPropertiesComponent::s_SimObjectCharacterPropertiesComponentList.mNode.mNext[-10] != &UFG::SimObjectCharacterPropertiesComponent::s_SimObjectCharacterPropertiesComponentList - 10 )
    {
      do
      {
        if ( ((__int64)v26[2].mPrev & 2) == 0 )
        {
          mNext = v26[2].mNext;
          v28 = mNext ? (UFG::TransformNodeComponent *)mNext[5].mNext : 0i64;
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
              v171 = (UFG::allocator::free_link *)v26[2].mNext;
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
                  v140 = v34;
                  v13 = v31;
                  v29 = v12;
                }
              }
              ++v12;
              v139 = v30;
              v11[v29].mNext = v171;
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
  *(_QWORD *)&result.v1.x = 0i64;
  v37 = 0.0;
  *(_QWORD *)&result.v0.z = 0i64;
  if ( *((_DWORD *)&search->mMotionBlurIsTimeLimited + 1) )
  {
    size = UFG::TSGameSlice::msInteriorTriggerData.size;
    if ( UFG::TSGameSlice::msInteriorTriggerData.size )
    {
      v39 = 8i64 * UFG::TSGameSlice::msInteriorTriggerData.size;
      if ( !is_mul_ok(UFG::TSGameSlice::msInteriorTriggerData.size, 8ui64) )
        v39 = -1i64;
      v40 = UFG::qMalloc(v39, "qArray.Reallocate(Reserve)", 0i64);
      *(_QWORD *)&result.v1.x = v40;
      v41 = size;
      LODWORD(result.v0.w) = size;
      if ( (_DWORD)size )
      {
        v171 = 0i64;
        v142 = size;
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
                  v10 = (__int64)v171;
                }
                ++LODWORD(v37);
                result.v0.z = v46;
                v42[LODWORD(v45)] = *(UFG::allocator::free_link *)&result.v1.z;
                size = v142;
              }
            }
          }
          v10 += 168i64;
          v171 = (UFG::allocator::free_link *)v10;
          v142 = --size;
        }
        while ( size );
        v12 = v139;
        v11 = v140;
        search = v170;
      }
    }
  }
  v53 = (int)(v12 - 1);
  for ( *(_QWORD *)&result.v1.z = v53; v53 >= 0; *(_QWORD *)&result.v1.z = --v53 )
  {
    v54 = (UFG::SimObjectCVBase *)v11[v53].mNext;
    if ( v54 != v145 )
    {
      if ( LODWORD(search->mView.v0.z) )
      {
        if ( v54 )
        {
          v56 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>((UFG::SimObjectCVBase *)v11[v53].mNext);
          if ( v56 )
          {
            m_CurrentObjective = v56->m_CurrentObjective;
            v58 = 0;
            x_low = LODWORD(search->mView.v1.x);
            if ( LODWORD(search->mView.v0.z) == 1 )
            {
              if ( !x_low )
                goto LABEL_94;
              while ( m_CurrentObjective != *(_DWORD *)(*(_QWORD *)&search->mView.v1.z + 4i64 * v58) )
              {
                if ( ++v58 >= x_low )
                  goto LABEL_94;
              }
              if ( v58 == -1 )
                goto LABEL_94;
            }
            else if ( x_low )
            {
              while ( m_CurrentObjective != *(_DWORD *)(*(_QWORD *)&search->mView.v1.z + 4i64 * v58) )
              {
                if ( ++v58 >= x_low )
                  goto LABEL_112;
              }
              if ( v58 != -1 )
                goto LABEL_94;
            }
          }
        }
      }
LABEL_112:
      if ( !LODWORD(search->mMotionBlur)
        || !v54
        || (v60 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v54)) == 0i64
        || (LODWORD(search->mMotionBlur) != 1
          ? (v61 = v60->m_eGender == eGENDER_FEMALE)
          : (v61 = v60->m_eGender == eGENDER_MALE),
            v61) )
      {
        if ( LODWORD(search->mDepthOfFieldFocus.mFarBlurRadius) )
        {
          if ( v54 )
          {
            v62 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v54);
            if ( v62 )
            {
              v63 = 0;
              v64 = *((_DWORD *)&search->mDepthOfFieldFocus + 7);
              if ( LODWORD(search->mDepthOfFieldFocus.mFarBlurRadius) == 1 )
              {
                if ( !v64 )
                  goto LABEL_94;
                while ( v62->m_symFactionClass.mUID != *(_DWORD *)(*(_QWORD *)&search->mView.v0.x + 4i64 * v63) )
                {
                  if ( ++v63 >= v64 )
                    goto LABEL_94;
                }
                if ( v63 == -1 )
                  goto LABEL_94;
              }
              else if ( v64 )
              {
                while ( v62->m_symFactionClass.mUID != *(_DWORD *)(*(_QWORD *)&search->mView.v0.x + 4i64 * v63) )
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
        v65 = *(_DWORD *)&search->mMotionBlurIsTimeLimited;
        if ( v65 )
        {
          if ( v65 == ALIVE_ALIVE )
          {
            IsKnockedOut = !UFG::IsKnockedOut(v54);
          }
          else
          {
            if ( v65 != ALIVE_DEAD )
              goto LABEL_94;
            IsKnockedOut = UFG::IsKnockedOut(v54);
          }
          if ( !IsKnockedOut )
            goto LABEL_94;
        }
        if ( LODWORD(search->mDesaturation) )
        {
          v67 = 1;
          if ( v54 )
          {
            v168 = (UFG::TransformNodeComponent *)v54->m_Components.p[2].m_pComponent;
            if ( v168 )
            {
              mCurrentCamera = UFG::Director::Get()->mCurrentCamera;
              p_mCamera = &mCurrentCamera->mCamera;
              if ( !mCurrentCamera )
                p_mCamera = 0i64;
              v170 = p_mCamera;
              ViewProjection = UFG::Camera::GetViewProjection(p_mCamera);
              WorldView = UFG::Camera::GetWorldView(v170);
              UFG::qMatrix44::operator*(WorldView, &result, ViewProjection);
              LODWORD(v72) = COERCE_UNSIGNED_INT(result.v0.x + result.v0.w) ^ _xmm[0];
              LODWORD(v73) = COERCE_UNSIGNED_INT(result.v1.x + result.v1.w) ^ _xmm[0];
              LODWORD(v74) = COERCE_UNSIGNED_INT(result.v2.x + result.v2.w) ^ _xmm[0];
              LODWORD(v75) = COERCE_UNSIGNED_INT(result.v0.w - result.v0.x) ^ _xmm[0];
              LODWORD(v76) = COERCE_UNSIGNED_INT(result.v1.w - result.v1.x) ^ _xmm[0];
              LODWORD(v77) = COERCE_UNSIGNED_INT(result.v2.w - result.v2.x) ^ _xmm[0];
              LODWORD(v170) = COERCE_UNSIGNED_INT(result.v3.w - result.v3.x) ^ _xmm[0];
              LODWORD(v78) = COERCE_UNSIGNED_INT(result.v0.y + result.v0.w) ^ _xmm[0];
              LODWORD(v172) = COERCE_UNSIGNED_INT(result.v1.y + result.v1.w) ^ _xmm[0];
              LODWORD(v171) = COERCE_UNSIGNED_INT(result.v2.y + result.v2.w) ^ _xmm[0];
              LODWORD(result.v0.x) = COERCE_UNSIGNED_INT(result.v3.y + result.v3.w) ^ _xmm[0];
              HIDWORD(v145) = COERCE_UNSIGNED_INT(result.v3.w - result.v3.y) ^ _xmm[0];
              LODWORD(v143) = COERCE_UNSIGNED_INT(result.v2.w - result.v2.z) ^ _xmm[0];
              LODWORD(v145) = COERCE_UNSIGNED_INT(result.v1.w - result.v1.z) ^ _xmm[0];
              LODWORD(v144) = COERCE_UNSIGNED_INT(result.v0.w - result.v0.z) ^ _xmm[0];
              v79 = fsqrt(
                      (float)((float)(COERCE_FLOAT(LODWORD(result.v1.z) ^ _xmm[0])
                                    * COERCE_FLOAT(LODWORD(result.v1.z) ^ _xmm[0]))
                            + (float)(COERCE_FLOAT(LODWORD(result.v0.z) ^ _xmm[0])
                                    * COERCE_FLOAT(LODWORD(result.v0.z) ^ _xmm[0])))
                    + (float)(COERCE_FLOAT(LODWORD(result.v2.z) ^ _xmm[0]) * COERCE_FLOAT(LODWORD(result.v2.z) ^ _xmm[0])));
              planes.x = COERCE_FLOAT(LODWORD(result.v0.z) ^ _xmm[0]) * (float)(1.0 / v79);
              planes.y = COERCE_FLOAT(LODWORD(result.v1.z) ^ _xmm[0]) * (float)(1.0 / v79);
              planes.z = COERCE_FLOAT(LODWORD(result.v2.z) ^ _xmm[0]) * (float)(1.0 / v79);
              planes.w = COERCE_FLOAT(LODWORD(result.v3.z) ^ _xmm[0]) * (float)(1.0 / v79);
              v80 = fsqrt((float)((float)(v73 * v73) + (float)(v72 * v72)) + (float)(v74 * v74));
              v148 = (float)(1.0 / v80) * v72;
              v149 = (float)(1.0 / v80) * v73;
              v150 = (float)(1.0 / v80) * v74;
              v151 = (float)(1.0 / v80) * COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v3.x + result.v3.w) ^ _xmm[0]);
              v81 = fsqrt((float)((float)(v76 * v76) + (float)(v75 * v75)) + (float)(v77 * v77));
              v152 = (float)(1.0 / v81) * v75;
              v153 = (float)(1.0 / v81) * v76;
              v154 = (float)(1.0 / v81) * v77;
              v155 = (float)(1.0 / v81) * *(float *)&v170;
              v82 = (__m128)(unsigned int)v172;
              v82.m128_f32[0] = (float)((float)(v82.m128_f32[0] * v82.m128_f32[0]) + (float)(v78 * v78))
                              + (float)(*(float *)&v171 * *(float *)&v171);
              v83 = _mm_sqrt_ps(v82).m128_f32[0];
              v156 = (float)(1.0 / v83) * v78;
              v157 = (float)(1.0 / v83) * *(float *)&v172;
              v158 = (float)(1.0 / v83) * *(float *)&v171;
              v159 = (float)(1.0 / v83) * result.v0.x;
              v84 = (__m128)COERCE_UNSIGNED_INT(result.v1.w - result.v1.y);
              v85 = v84;
              LODWORD(v86) = COERCE_UNSIGNED_INT(result.v0.w - result.v0.y) ^ _xmm[0];
              v85.m128_f32[0] = (float)((float)(v84.m128_f32[0] * v84.m128_f32[0]) + (float)(v86 * v86))
                              + (float)((float)(result.v1.w - result.v1.y) * (float)(result.v1.w - result.v1.y));
              v87 = _mm_sqrt_ps(v85).m128_f32[0];
              v160 = (float)(1.0 / v87) * v86;
              v161 = (float)(1.0 / v87) * v84.m128_f32[0];
              v162 = (float)(1.0 / v87) * (float)(result.v1.w - result.v1.y);
              v163 = (float)(1.0 / v87) * *((float *)&v145 + 1);
              v88 = (__m128)(unsigned int)v145;
              v88.m128_f32[0] = (float)((float)(v88.m128_f32[0] * v88.m128_f32[0]) + (float)(v144 * v144))
                              + (float)(v143 * v143);
              v89 = 1.0 / _mm_sqrt_ps(v88).m128_f32[0];
              v164 = v89 * v144;
              v165 = v89 * *(float *)&v145;
              v166 = v143 * v89;
              v167 = COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v3.w - result.v3.z) ^ _xmm[0]) * v89;
              v90 = v168;
              UFG::TransformNodeComponent::UpdateWorldTransform(v168);
              v67 = IntersectSphereFrustum(&planes, (UFG::qVector3 *)&v90->mWorldTransform.v3, 2.0) != 2;
            }
          }
          if ( LODWORD(search->mDesaturation) != 1 )
            v67 = !v67;
          if ( !v67 )
            goto LABEL_94;
        }
        mMotionBlurTimeLimit = search->mMotionBlurTimeLimit;
        if ( mMotionBlurTimeLimit )
        {
          if ( v54 )
            v92 = v54->m_Components.p[44].m_pComponent;
          else
            v92 = 0i64;
          v93 = v92 != 0i64;
          if ( mMotionBlurTimeLimit != INVEHICLE_INVEHICLE )
            v93 = !v93;
          if ( !v93 )
            goto LABEL_94;
        }
        if ( LODWORD(search->mDepthOfFieldFocus.mInFocusRange) )
        {
          mUID = UFG::gNullQSymbol.mUID;
          if ( v54 )
          {
            v95 = (UFG::StreamedResourceComponent *)v54->m_Components.p[10].m_pComponent;
            if ( v95 )
              mUID = UFG::StreamedResourceComponent::GetSpawnPriority(v95, 0i64)->mUID;
          }
          v96 = mUID == LODWORD(search->mDepthOfFieldFocus.mNearRange);
          if ( LODWORD(search->mDepthOfFieldFocus.mInFocusRange) == 2 )
            v96 = !v96;
          if ( !v96 )
            goto LABEL_94;
        }
        if ( LODWORD(search->mDepthOfFieldFocus.mNearBlurRadius) )
        {
          v97 = 0;
          if ( (dword_14240D784 & 1) == 0 )
          {
            dword_14240D784 |= 1u;
            dword_14240D780 = UFG::InventoryComponent::GetSlotTarget(eINVENTORY_EQUIP_SLOT_RIGHT_HAND);
          }
          if ( v54 )
          {
            v98 = v54->m_Components.p[20].m_pComponent;
            if ( v98 )
            {
              v99 = *(UFG::SimObject **)(56i64
                                       * *(unsigned __int8 *)(*(_QWORD *)&v98[1].m_Flags
                                                            + (unsigned int)dword_14240D780
                                                            + 8i64)
                                       + *(_QWORD *)&v98[1].m_TypeUID
                                       + 40);
              if ( v99 )
              {
                ComponentOfType = UFG::SimObject::GetComponentOfType(v99, UFG::InventoryItemComponent::_TypeUID);
                if ( ComponentOfType )
                {
                  m_pSimObject = (int)ComponentOfType[1].m_pSimObject;
                  v97 = m_pSimObject && LODWORD(search->mDepthOfFieldFocus.mFarRange) == m_pSimObject;
                }
              }
            }
          }
          if ( LODWORD(search->mDepthOfFieldFocus.mNearBlurRadius) != 1 )
            v97 = !v97;
          if ( !v97 )
            goto LABEL_94;
        }
        if ( LODWORD(search->mDepthOfFieldFocus.mFocalDistance) )
        {
          v102 = 0;
          if ( v54 )
          {
            v103 = v54->m_Components.p[20].m_pComponent;
            if ( v103 )
            {
              v104 = *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v103[1].m_Flags + 34i64)
                                        + *(_QWORD *)&v103[1].m_TypeUID
                                        + 40);
              if ( v104 )
              {
                m_Flags = v104->m_Flags;
                if ( (m_Flags & 0x4000) != 0 )
                {
                  v106 = v104->m_Components.p[25].m_pComponent;
                }
                else if ( m_Flags >= 0 )
                {
                  if ( (m_Flags & 0x2000) != 0 )
                  {
                    v106 = v104->m_Components.p[10].m_pComponent;
                  }
                  else if ( (m_Flags & 0x1000) != 0 )
                  {
                    v106 = v104->m_Components.p[3].m_pComponent;
                  }
                  else
                  {
                    v106 = UFG::SimObject::GetComponentOfType(v104, UFG::InterestPoint::_TypeUID);
                  }
                }
                else
                {
                  v106 = v104->m_Components.p[25].m_pComponent;
                }
                v102 = v106 != 0i64;
              }
            }
          }
          if ( LODWORD(search->mDepthOfFieldFocus.mFocalDistance) != 1 )
            v102 = !v102;
          if ( !v102 )
            goto LABEL_94;
        }
        if ( !HIDWORD(search->mMotionBlurTimeLimit) )
          goto LABEL_203;
        v107 = PropertyUtils::Get<bool>(v54->m_pSceneObj, (UFG::qArray<unsigned long,0> *)&qSymbol_ScenarioControl);
        if ( v107 )
        {
          v108 = *v107;
        }
        else
        {
          PropertyUtils::SetRuntime<bool>(v54->m_pSceneObj, (UFG::qArray<unsigned long,0> *)&qSymbol_ScenarioControl, 0);
          v108 = 0;
        }
        mMotionBlurTimeLimit_high = HIDWORD(search->mMotionBlurTimeLimit);
        if ( mMotionBlurTimeLimit_high != SCENARIOCONTROL_YES )
        {
          if ( mMotionBlurTimeLimit_high != SCENARIOCONTROL_NO )
            goto LABEL_94;
          v108 = !v108;
        }
        if ( v108 )
        {
LABEL_203:
          if ( !LODWORD(search->mView.v2.x) )
            goto LABEL_234;
          v110 = 0;
          m_pSceneObj = v54->m_pSceneObj;
          mpWritableProperties = m_pSceneObj->mpWritableProperties;
          if ( !mpWritableProperties )
            mpWritableProperties = m_pSceneObj->mpConstProperties;
          v113 = UFG::qPropertySet::Get<UFG::qPropertySet>(
                   mpWritableProperties,
                   (UFG::qArray<unsigned long,0> *)&schema_classlist::sPropertyName,
                   DEPTH_RECURSE);
          if ( v113 )
          {
            MemImagePtr = UFG::qPropertySet::GetMemImagePtr(v113);
            if ( MemImagePtr )
            {
              v115 = *((_QWORD *)MemImagePtr + 1);
              if ( v115 )
              {
                v116 = (UFG::qPropertyList *)&MemImagePtr[v115 + 8];
                if ( v116 )
                {
                  mNumElements = v116->mNumElements;
                  v118 = mNumElements ? UFG::qPropertyList::Get<UFG::qSymbol>(v116, 0) : 0i64;
                  v119 = 0;
                  if ( mNumElements )
                  {
                    z_low = LODWORD(search->mView.v2.z);
                    do
                    {
                      v121 = 0;
                      if ( z_low )
                      {
                        while ( v118[v119].mUID != *(_DWORD *)(*(_QWORD *)&search->mView.v3.x + 4i64
                                                                                              * (unsigned int)v121) )
                        {
                          if ( ++v121 >= z_low )
                            goto LABEL_218;
                        }
                      }
                      else
                      {
LABEL_218:
                        v121 = -1;
                      }
                      v110 = v121 != -1;
                      if ( v121 != -1 )
                        break;
                      ++v119;
                    }
                    while ( v119 < mNumElements );
                    v53 = *(_QWORD *)&result.v1.z;
                    v37 = result.v0.z;
                  }
                }
              }
            }
          }
          if ( LODWORD(search->mView.v2.x) != 1 )
            v110 = !v110;
          if ( v110 )
          {
LABEL_234:
            if ( !*((_DWORD *)&search->mMotionBlurIsTimeLimited + 1) )
              continue;
            v122 = 0;
            LOBYTE(v170) = 0;
            v123 = 0;
            if ( v37 != 0.0 )
            {
              v124 = *(_QWORD *)&result.v1.x;
              while ( !UFG::RegionComponent::IsHitPoint(
                         *(UFG::RegionComponent **)(*(_QWORD *)v124 + 216i64),
                         (UFG::qVector3 *)&result.v2) )
              {
                ++v123;
                v124 += 8i64;
                if ( v123 >= LODWORD(v37) )
                {
                  v122 = (char)v170;
                  goto LABEL_232;
                }
              }
              v122 = 1;
            }
LABEL_232:
            if ( *((_DWORD *)&search->mMotionBlurIsTimeLimited + 1) != 1 )
              v122 = v122 == 0;
            if ( v122 )
              continue;
          }
        }
      }
    }
LABEL_94:
    v55 = v12 - 1;
    v11[v53] = v11[v55];
    if ( v12 <= 1 )
      LODWORD(v55) = 0;
    v12 = v55;
  }
  v125 = (SSList *)AMemory::c_malloc_func(0x18ui64, "SSList");
  v126 = v125;
  v170 = (UFG::Camera *)v125;
  if ( v125 )
  {
    v125->i_items.i_count = 0;
    v125->i_items.i_array_p = 0i64;
    v125->i_items.i_size = 0;
    v125->i_items.i_array_p = (SSInstance **)AMemory::c_malloc_func(0i64, "APArrayBase.buffer");
  }
  else
  {
    v126 = 0i64;
  }
  for ( i = (int)(v12 - 1); i >= 0; --i )
  {
    v128 = v11[i].mNext;
    if ( v128 )
      v129 = (UFG::TSActorComponent *)v128[13].mNext[8].mNext;
    else
      v129 = 0i64;
    Actor = UFG::TSActorComponent::GetActor(v129);
    v131 = v126->i_items.i_count;
    if ( v126->i_items.i_size < (unsigned int)(v131 + 1) )
    {
      i_array_p = v126->i_items.i_array_p;
      if ( (_DWORD)v131 == -1 )
        LODWORD(v133) = 0;
      else
        v133 = (unsigned __int64)AMemory::c_req_byte_size_func(32 * (((unsigned int)v131 >> 2) + 1)) >> 3;
      v126->i_items.i_size = v133;
      v134 = APArrayBase<SSActor>::alloc_array(v133);
      v126->i_items.i_array_p = v134;
      memmove(v134, i_array_p, 8 * v131);
      AMemory::c_free_func(i_array_p);
    }
    v126->i_items.i_array_p[v131] = Actor;
    ++v126->i_items.i_count;
  }
  v135 = v126->i_items.i_count;
  if ( (_DWORD)v135 )
  {
    v136 = (ARefCountMix<SSInstance> **)v126->i_items.i_array_p;
    for ( j = &v136[v135]; v136 < j; ++v136 )
      UFG::PersistentData::MapFloat::Iterator::Next(*v136 + 4);
  }
  v138 = SSList::as_instance(v126);
  *v173 = v138;
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
  SSObjectBase *i_obj_p; // r8
  UFG::Camera *vfptr; // rsi
  SSActor *i_data_p; // rbx
  SSClass *i_class_p; // rdi

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  vfptr = (UFG::Camera *)i_obj_p[2].vfptr;
  i_data_p = (SSActor *)(*pScope->i_data.i_array_p)->i_data_p;
  if ( !i_data_p )
    goto LABEL_9;
  i_class_p = i_data_p->i_class_p;
  if ( !i_class_p->vfptr->is_actor_class(i_class_p) )
  {
    if ( i_class_p == SSBrain::c_symbol_class_p && LODWORD(i_data_p->i_user_data) != -1 )
    {
      i_data_p = SSActor::find((ASymbol *)&i_data_p->i_user_data);
      goto LABEL_10;
    }
LABEL_9:
    i_data_p = 0i64;
  }
LABEL_10:
  UFG::TSCharacterSearch::DoSearch(vfptr, (UFG::TSCharacter *)i_data_p, 0i64, ppResult);
}

// File Line: 991
// RVA: 0x5062E0
void __fastcall UFG::TSCharacterSearch::Mthd_refine_search(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r8
  UFG::Camera *vfptr; // rbp
  SSActor *i_data_p; // rbx
  SSClass *i_class_p; // rsi

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  vfptr = (UFG::Camera *)i_obj_p[2].vfptr;
  i_data_p = (SSActor *)(*pScope->i_data.i_array_p)->i_data_p;
  if ( !i_data_p )
    goto LABEL_9;
  i_class_p = i_data_p->i_class_p;
  if ( !i_class_p->vfptr->is_actor_class(i_class_p) )
  {
    if ( i_class_p == SSBrain::c_symbol_class_p && LODWORD(i_data_p->i_user_data) != -1 )
    {
      i_data_p = SSActor::find((ASymbol *)&i_data_p->i_user_data);
      goto LABEL_10;
    }
LABEL_9:
    i_data_p = 0i64;
  }
LABEL_10:
  UFG::TSCharacterSearch::DoSearch(
    vfptr,
    (UFG::TSCharacter *)i_data_p,
    *(SSList **)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 1) + 8i64) + 32i64),
    ppResult);
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
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSCharacterSearch::mspCharacterSearchClass,
    &ASymbolX_dtor,
    UFG::TSCharacterSearch::Mthd_destructor,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSCharacterSearch::mspCharacterSearchClass,
    "set_radius",
    UFG::TSCharacterSearch::Mthd_set_radius,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSCharacterSearch::mspCharacterSearchClass,
    "alive_exclude",
    UFG::TSCharacterSearch::Mthd_alive_exclude,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSCharacterSearch::mspCharacterSearchClass,
    "alive_include",
    UFG::TSCharacterSearch::Mthd_alive_include,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSCharacterSearch::mspCharacterSearchClass,
    "faction_exclude",
    UFG::TSCharacterSearch::Mthd_faction_exclude,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSCharacterSearch::mspCharacterSearchClass,
    "faction_include",
    UFG::TSCharacterSearch::Mthd_faction_include,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSCharacterSearch::mspCharacterSearchClass,
    "gender_exclude",
    UFG::TSCharacterSearch::Mthd_gender_exclude,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSCharacterSearch::mspCharacterSearchClass,
    "gender_include",
    UFG::TSCharacterSearch::Mthd_gender_include,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSCharacterSearch::mspCharacterSearchClass,
    "indoors_exclude",
    UFG::TSCharacterSearch::Mthd_indoors_exclude,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSCharacterSearch::mspCharacterSearchClass,
    "indoors_include",
    UFG::TSCharacterSearch::Mthd_indoors_include,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSCharacterSearch::mspCharacterSearchClass,
    "invehicle_exclude",
    UFG::TSCharacterSearch::Mthd_invehicle_exclude,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSCharacterSearch::mspCharacterSearchClass,
    "invehicle_include",
    UFG::TSCharacterSearch::Mthd_invehicle_include,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSCharacterSearch::mspCharacterSearchClass,
    "objective_exclude",
    UFG::TSCharacterSearch::Mthd_objective_exclude,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSCharacterSearch::mspCharacterSearchClass,
    "objective_include",
    UFG::TSCharacterSearch::Mthd_objective_include,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSCharacterSearch::mspCharacterSearchClass,
    "spawnpriority_exclude",
    UFG::TSCharacterSearch::Mthd_spawnpriority_exclude,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSCharacterSearch::mspCharacterSearchClass,
    "spawnpriority_include",
    UFG::TSCharacterSearch::Mthd_spawnpriority_include,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSCharacterSearch::mspCharacterSearchClass,
    "equiped_item_exclude",
    UFG::TSCharacterSearch::Mthd_equiped_item_exclude,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSCharacterSearch::mspCharacterSearchClass,
    "equiped_item_include",
    UFG::TSCharacterSearch::Mthd_equiped_item_include,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSCharacterSearch::mspCharacterSearchClass,
    "scenariocontrol_exclude",
    UFG::TSCharacterSearch::Mthd_scenariocontrol_exclude,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSCharacterSearch::mspCharacterSearchClass,
    "scenariocontrol_include",
    UFG::TSCharacterSearch::Mthd_scenariocontrol_include,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSCharacterSearch::mspCharacterSearchClass,
    "inview_exclude",
    UFG::TSCharacterSearch::Mthd_alive_exclude,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSCharacterSearch::mspCharacterSearchClass,
    "inview_include",
    UFG::TSCharacterSearch::Mthd_alive_include,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSCharacterSearch::mspCharacterSearchClass,
    "character_type_exclude",
    UFG::TSCharacterSearch::Mthd_character_type_exclude,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSCharacterSearch::mspCharacterSearchClass,
    "character_type_include",
    UFG::TSCharacterSearch::Mthd_character_type_include,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSCharacterSearch::mspCharacterSearchClass,
    "using_poi_exclude",
    UFG::TSCharacterSearch::Mthd_using_poi_exclude,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSCharacterSearch::mspCharacterSearchClass,
    "using_poi_include",
    UFG::TSCharacterSearch::Mthd_using_poi_include,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSCharacterSearch::mspCharacterSearchClass,
    "search",
    UFG::TSCharacterSearch::Mthd_search,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSCharacterSearch::mspCharacterSearchClass,
    "refine_search",
    UFG::TSCharacterSearch::Mthd_refine_search,
    SSBindFlag_instance_no_rebind);
}

