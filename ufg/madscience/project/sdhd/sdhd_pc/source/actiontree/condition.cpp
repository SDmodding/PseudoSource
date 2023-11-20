// File Line: 93
// RVA: 0x1480510
__int64 dynamic_initializer_for__ConditionGroup::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("ConditionGroup", 0xFFFFFFFF);
  ConditionGroup::sClassNameUID = result;
  return result;
}

// File Line: 103
// RVA: 0x26CE00
ConditionGroup *__fastcall ConditionGroup::CreateClone(ConditionGroup *this)
{
  ConditionGroup *v1; // rdi
  char *v2; // rax
  ConditionGroup *v3; // rbx

  v1 = this;
  v2 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x30ui64, "ConditionGroup::CreateClone", 0i64, 1u);
  v3 = (ConditionGroup *)v2;
  if ( v2 )
  {
    *(_QWORD *)v2 = &Expression::IMemberMap::`vftable;
    *((_QWORD *)v2 + 1) = 0i64;
    *(_QWORD *)v2 = &Condition::`vftable;
    v2[23] = 0;
    *(_QWORD *)v2 = &ConditionGroup::`vftable;
    *((_QWORD *)v2 + 3) = -1i64;
    *((_DWORD *)v2 + 8) = 0;
    *((_QWORD *)v2 + 5) = 0i64;
  }
  else
  {
    v3 = 0i64;
  }
  ConditionGroup::CopyFrom(v3, v1);
  return v3;
}

// File Line: 124
// RVA: 0x26C4D0
void __fastcall ConditionGroup::CopyFrom(ConditionGroup *this, ConditionGroup *other_condition_group)
{
  __int64 v2; // rdi
  ConditionGroup *v3; // rbx
  char *v4; // r14
  ConditionGroup *v5; // rsi
  Condition *v6; // rax

  if ( other_condition_group )
  {
    v2 = 0i64;
    v3 = other_condition_group;
    v4 = (char *)&other_condition_group->mConditions.mData + other_condition_group->mConditions.mData.mOffset;
    v5 = this;
    if ( other_condition_group->mConditions.mCount & 0x7FFFFFFF )
    {
      do
      {
        v6 = (Condition *)(*(__int64 (**)(void))(*(_QWORD *)&v4[8 * v2 + *(_QWORD *)&v4[8 * v2]] + 16i64))();
        BinPtrArray<ActionNode,0,0>::Add(&v5->mConditions, v6, "BinPtrArray.Add");
        ConditionGroup::UpdateSignalAndConditionMask(v5);
        v2 = (unsigned int)(v2 + 1);
      }
      while ( (unsigned int)v2 < (v3->mConditions.mCount & 0x7FFFFFFFu) );
    }
  }
}

// File Line: 178
// RVA: 0x272060
void __fastcall ConditionGroup::ResortEntries(ConditionGroup *this)
{
  __int64 v1; // rbp
  ConditionGroup *v2; // rsi
  __int64 v3; // r15
  signed __int64 v4; // r14
  __int64 v5; // rax
  signed __int64 v6; // rcx
  signed __int64 v7; // rdi
  _QWORD *v8; // rax
  char *v9; // rbx
  __int64 v10; // rax
  signed __int64 v11; // rcx
  signed __int64 v12; // rax
  __int64 v13; // rcx
  signed __int64 v14; // r9
  signed __int64 i; // r8
  __int64 v16; // rcx
  signed __int64 v17; // rax
  signed __int64 v18; // rdx
  __int64 v19; // rax
  signed __int64 v20; // rdx
  signed __int64 v21; // rcx
  _QWORD *v22; // rax
  __int64 v23; // rax
  signed __int64 v24; // rcx
  signed __int64 v25; // rax
  __int64 v26; // rcx
  signed __int64 v27; // r11
  __int64 v28; // r10
  __int64 v29; // r9
  __int64 v30; // rcx
  signed __int64 v31; // rdx
  signed __int64 v32; // r8
  __int64 v33; // rax
  signed __int64 v34; // rdx
  signed __int64 v35; // rcx
  __int64 v36; // rcx
  signed __int64 v37; // rdx

  v1 = 0i64;
  v2 = this;
  if ( this->mConditions.mCount & 0x7FFFFFFF )
  {
    v3 = 0i64;
    v4 = -1i64;
    do
    {
      v5 = v2->mConditions.mData.mOffset;
      if ( v5 )
        v6 = (signed __int64)&v2->mConditions.mData + v5;
      else
        v6 = 0i64;
      v7 = 8 * v1;
      v8 = (_QWORD *)(8 * v1 + v6);
      if ( *v8 )
        v9 = (char *)v8 + *v8;
      else
        v9 = 0i64;
      if ( (*(unsigned __int8 (__fastcall **)(char *))(*(_QWORD *)v9 + 136i64))(v9) )
      {
        v10 = v2->mConditions.mData.mOffset;
        if ( v10 )
          v11 = (signed __int64)&v2->mConditions.mData + v10;
        else
          v11 = 0i64;
        v12 = v7 + v11;
        v13 = *(_QWORD *)(v7 + v11);
        if ( v13 )
          v14 = v13 + v12;
        else
          v14 = 0i64;
        for ( i = v4; i >= 0; *(_QWORD *)v21 = v19 )
        {
          v16 = v2->mConditions.mData.mOffset;
          if ( v16 )
            v17 = (signed __int64)&v2->mConditions.mData + v16;
          else
            v17 = 0i64;
          v18 = v17 + 8 * i;
          v19 = *(_QWORD *)(v17 + 8 * i);
          if ( v19 )
            v19 += v18;
          if ( v16 )
            v20 = (signed __int64)&v2->mConditions.mData + v16;
          else
            v20 = 0i64;
          v21 = v20 + 8 * (i + 1);
          if ( v19 )
            v19 -= v21;
          --i;
        }
        v22 = (_QWORD *)v2->mConditions.mData.mOffset;
        if ( v22 )
          v22 = (_QWORD *)((char *)v22 + (_QWORD)v2 + 40);
        if ( v14 )
          *v22 = v14 - (_QWORD)v22;
        else
          *v22 = 0i64;
      }
      else if ( (*(unsigned __int8 (__fastcall **)(char *))(*(_QWORD *)v9 + 144i64))(v9) )
      {
        v23 = v2->mConditions.mData.mOffset;
        if ( v23 )
          v24 = (signed __int64)&v2->mConditions.mData + v23;
        else
          v24 = 0i64;
        v25 = v7 + v24;
        v26 = *(_QWORD *)(v7 + v24);
        if ( v26 )
          v27 = v26 + v25;
        else
          v27 = 0i64;
        LODWORD(v28) = v1;
        if ( (unsigned int)v1 < (v2->mConditions.mCount & 0x7FFFFFFFu) - 1 )
        {
          v29 = v3;
          do
          {
            v30 = v2->mConditions.mData.mOffset;
            if ( v30 )
              v31 = (signed __int64)&v2->mConditions.mData + v30;
            else
              v31 = 0i64;
            v28 = (unsigned int)(v28 + 1);
            v32 = v31 + 8 * v28;
            v33 = *(_QWORD *)v32;
            if ( *(_QWORD *)v32 )
              v33 += v32;
            if ( v30 )
              v34 = (signed __int64)&v2->mConditions.mData + v30;
            else
              v34 = 0i64;
            v35 = v29 + v34;
            if ( v33 )
              v33 -= v35;
            *(_QWORD *)v35 = v33;
            v29 += 8i64;
          }
          while ( (unsigned int)v28 < (v2->mConditions.mCount & 0x7FFFFFFFu) - 1 );
        }
        v36 = v2->mConditions.mData.mOffset;
        if ( v36 )
          v36 += (__int64)&v2->mConditions.mData;
        v37 = v36 + 8i64 * ((v2->mConditions.mCount & 0x7FFFFFFF) - 1);
        if ( v27 )
          v27 -= v37;
        *(_QWORD *)v37 = v27;
      }
      v1 = (unsigned int)(v1 + 1);
      ++v4;
      v3 += 8i64;
    }
    while ( (unsigned int)v1 < (v2->mConditions.mCount & 0x7FFFFFFFu) );
  }
  ConditionGroup::UpdateSignalAndConditionMask(v2);
}

// File Line: 217
// RVA: 0x14882D0
__int64 dynamic_initializer_for__gOrCondition__()
{
  gOrCondition.mBreakPoint = 0;
  gOrCondition.vfptr = (Expression::IMemberMapVtbl *)&ORCondition::`vftable;
  return atexit(dynamic_atexit_destructor_for__gOrCondition__);
}

// File Line: 218
// RVA: 0x1488290
__int64 dynamic_initializer_for__gNotCondition__()
{
  gNotCondition.mBreakPoint = 0;
  gNotCondition.vfptr = (Expression::IMemberMapVtbl *)&NotCondition::`vftable;
  return atexit(dynamic_atexit_destructor_for__gNotCondition__);
}

// File Line: 237
// RVA: 0x26F9B0
bool __fastcall ConditionGroup::Match(ConditionGroup *this, ActionContext *context)
{
  unsigned __int64 v2; // rax
  ActionContext *v3; // rbp
  ConditionGroup *v4; // rsi
  signed int v6; // ebx
  bool v7; // dl
  char *v8; // r14
  __int64 v9; // rdi
  signed __int64 v10; // r8
  signed int v11; // eax
  char v12; // al

  v2 = this->mSignalMask;
  v3 = context;
  v4 = this;
  if ( v2 != -1i64 && !(v2 & context->mSignals) && !ActionNode::sEnableNodeBreakPoints )
    return 0;
  v6 = 1;
  v7 = 1;
  v8 = (char *)&this->mConditions.mData + this->mConditions.mData.mOffset;
  v9 = 0i64;
  while ( (unsigned int)v9 < (v4->mConditions.mCount & 0x7FFFFFFFu) )
  {
    v10 = (signed __int64)&v8[8 * v9 + *(_QWORD *)&v8[8 * v9]];
    v11 = *(_DWORD *)v10 == LODWORD(gOrCondition.vfptr) ? 4 : (*(_DWORD *)v10 == LODWORD(gNotCondition.vfptr)) + 1;
    if ( !v7 && v11 != 4 && !(v6 & 0xC) )
      break;
    if ( v11 == 1 )
    {
      if ( !v7 || !(v6 & 0xC) )
      {
        v12 = (*(__int64 (__fastcall **)(char *, ActionContext *))(*(_QWORD *)v10 + 80i64))(
                &v8[8 * v9 + *(_QWORD *)&v8[8 * v9]],
                v3);
        v7 = v12;
        if ( v6 & 0xA )
          v7 = v12 == 0;
      }
      v6 = 1;
      v9 = (unsigned int)(v9 + 1);
    }
    else if ( v11 == 4 )
    {
      v6 = 4;
      v9 = (unsigned int)(v9 + 1);
    }
    else
    {
      if ( v11 == 2 )
      {
        if ( v6 == 4 )
          v11 = 8;
        v6 = v11;
      }
      v9 = (unsigned int)(v9 + 1);
    }
  }
  return v7;
}

// File Line: 507
// RVA: 0x2738C0
void __fastcall ConditionGroup::UpdateSignalAndConditionMask(ConditionGroup *this)
{
  signed __int64 v1; // rdi
  int v2; // ebp
  ConditionGroup *v3; // r13
  signed __int64 v4; // rbx
  char *v5; // r12
  signed int v6; // esi
  unsigned int v7; // er15
  signed __int64 v8; // r14
  signed int v9; // eax
  __int64 v10; // rax
  __int64 v11; // rax
  __int64 v12; // r9
  signed __int64 v13; // rax
  int i; // er8
  signed __int64 v15; // rcx
  int j; // edx
  signed __int64 v17; // rcx
  int k; // edx
  signed __int64 l; // rcx

  v1 = -1i64;
  v2 = 0;
  v3 = this;
  v4 = -1i64;
  v5 = (char *)&this->mConditions.mData + this->mConditions.mData.mOffset;
  v6 = 1;
  v7 = 0;
  if ( !(this->mConditions.mCount & 0x7FFFFFFF) )
    goto LABEL_37;
  do
  {
    v8 = (signed __int64)&v5[8 * v7 + *(_QWORD *)&v5[8 * v7]];
    v9 = (*(__int64 (__fastcall **)(signed __int64))(*(_QWORD *)v8 + 88i64))(v8);
    switch ( v9 )
    {
      case 1:
        v10 = *(_QWORD *)v8;
        if ( v6 & 0xA )
          v11 = (*(__int64 (__fastcall **)(signed __int64))(v10 + 104))(v8);
        else
          v11 = (*(__int64 (__fastcall **)(signed __int64))(v10 + 96))(v8);
        v12 = v11;
        if ( v6 & 0xC )
        {
          v4 |= v11;
          v6 = 1;
        }
        else if ( v1 == -1 )
        {
          v1 = v4;
          v6 = 1;
          v4 = v11;
        }
        else
        {
          if ( v4 != -1 )
          {
            v13 = v1;
            for ( i = 0; v13; v13 &= v13 - 1 )
              ++i;
            v15 = v4;
            for ( j = 0; v15; v15 &= v15 - 1 )
              ++j;
            if ( i > j )
              v1 = v4;
          }
          v4 = v12;
          v6 = 1;
        }
        break;
      case 4:
        v6 = 4;
        break;
      case 2:
        if ( v6 == 4 )
          v9 = 8;
        v6 = v9;
        break;
    }
    ++v7;
  }
  while ( v7 < (v3->mConditions.mCount & 0x7FFFFFFFu) );
  if ( v1 != -1 )
  {
    if ( v4 != -1 )
    {
      v17 = v1;
      for ( k = 0; v17; v17 &= v17 - 1 )
        ++k;
      for ( l = v4; l; l &= l - 1 )
        ++v2;
      if ( k > v2 )
        v1 = v4;
    }
    v3->mSignalMask = v1;
  }
  else
  {
LABEL_37:
    v3->mSignalMask = v4;
  }
}

// File Line: 615
// RVA: 0x268B80
void __fastcall Condition::Condition(Condition *this)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
  this->mResourceOwner = 0i64;
  this->vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable;
  this->mBreakPoint = 0;
}

