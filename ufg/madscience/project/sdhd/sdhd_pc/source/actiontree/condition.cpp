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
  char *v2; // rax
  ConditionGroup *v3; // rbx

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
  ConditionGroup::CopyFrom(v3, this);
  return v3;
}

// File Line: 124
// RVA: 0x26C4D0
void __fastcall ConditionGroup::CopyFrom(ConditionGroup *this, ConditionGroup *other_condition_group)
{
  __int64 v2; // rdi
  char *v4; // r14
  __int64 v6; // rcx
  Condition *v7; // rax

  if ( other_condition_group )
  {
    v2 = 0i64;
    v4 = (char *)&other_condition_group->mConditions.mData + other_condition_group->mConditions.mData.mOffset;
    if ( (other_condition_group->mConditions.mCount & 0x7FFFFFFF) != 0 )
    {
      do
      {
        v6 = (__int64)&v4[8 * v2 + *(_QWORD *)&v4[8 * v2]];
        v7 = (Condition *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v6 + 16i64))(v6);
        BinPtrArray<ActionNode,0,0>::Add(&this->mConditions, v7, "BinPtrArray.Add");
        ConditionGroup::UpdateSignalAndConditionMask(this);
        v2 = (unsigned int)(v2 + 1);
      }
      while ( (unsigned int)v2 < (other_condition_group->mConditions.mCount & 0x7FFFFFFFu) );
    }
  }
}

// File Line: 178
// RVA: 0x272060
void __fastcall ConditionGroup::ResortEntries(ConditionGroup *this)
{
  __int64 v1; // rbp
  __int64 v3; // r15
  __int64 v4; // r14
  __int64 mOffset; // rax
  char *v6; // rcx
  __int64 v7; // rdi
  char *v8; // rax
  char *v9; // rbx
  __int64 v10; // rax
  char *v11; // rcx
  char *v12; // rax
  __int64 v13; // rcx
  char *v14; // r9
  __int64 i; // r8
  __int64 v16; // rcx
  char *v17; // rax
  char *v18; // rdx
  __int64 v19; // rax
  char *v20; // rdx
  char *v21; // rcx
  char *v22; // rax
  __int64 v23; // rax
  char *v24; // rcx
  char *v25; // rax
  __int64 v26; // rcx
  char *v27; // r11
  __int64 v28; // r10
  __int64 v29; // r9
  __int64 v30; // rcx
  char *v31; // rdx
  char *v32; // r8
  __int64 v33; // rax
  char *v34; // rdx
  char *v35; // rcx
  __int64 v36; // rcx
  __int64 v37; // rdx

  v1 = 0i64;
  if ( (this->mConditions.mCount & 0x7FFFFFFF) != 0 )
  {
    v3 = 0i64;
    v4 = -1i64;
    do
    {
      mOffset = this->mConditions.mData.mOffset;
      if ( mOffset )
        v6 = (char *)&this->mConditions.mData + mOffset;
      else
        v6 = 0i64;
      v7 = 8 * v1;
      v8 = &v6[8 * v1];
      if ( *(_QWORD *)v8 )
        v9 = &v8[*(_QWORD *)v8];
      else
        v9 = 0i64;
      if ( (*(unsigned __int8 (__fastcall **)(char *))(*(_QWORD *)v9 + 136i64))(v9) )
      {
        v10 = this->mConditions.mData.mOffset;
        if ( v10 )
          v11 = (char *)&this->mConditions.mData + v10;
        else
          v11 = 0i64;
        v12 = &v11[v7];
        v13 = *(_QWORD *)&v11[v7];
        if ( v13 )
          v14 = &v12[v13];
        else
          v14 = 0i64;
        for ( i = v4; i >= 0; *(_QWORD *)v21 = v19 )
        {
          v16 = this->mConditions.mData.mOffset;
          if ( v16 )
            v17 = (char *)&this->mConditions.mData + v16;
          else
            v17 = 0i64;
          v18 = &v17[8 * i];
          v19 = *(_QWORD *)v18;
          if ( *(_QWORD *)v18 )
            v19 += (__int64)v18;
          if ( v16 )
            v20 = (char *)&this->mConditions.mData + v16;
          else
            v20 = 0i64;
          v21 = &v20[8 * i + 8];
          if ( v19 )
            v19 -= (__int64)v21;
          --i;
        }
        v22 = (char *)this->mConditions.mData.mOffset;
        if ( v22 )
          v22 = &v22[(_QWORD)this + 40];
        if ( v14 )
          *(_QWORD *)v22 = v14 - v22;
        else
          *(_QWORD *)v22 = 0i64;
      }
      else if ( (*(unsigned __int8 (__fastcall **)(char *))(*(_QWORD *)v9 + 144i64))(v9) )
      {
        v23 = this->mConditions.mData.mOffset;
        if ( v23 )
          v24 = (char *)&this->mConditions.mData + v23;
        else
          v24 = 0i64;
        v25 = &v24[v7];
        v26 = *(_QWORD *)&v24[v7];
        if ( v26 )
          v27 = &v25[v26];
        else
          v27 = 0i64;
        LODWORD(v28) = v1;
        if ( (unsigned int)v1 < (this->mConditions.mCount & 0x7FFFFFFFu) - 1 )
        {
          v29 = v3;
          do
          {
            v30 = this->mConditions.mData.mOffset;
            if ( v30 )
              v31 = (char *)&this->mConditions.mData + v30;
            else
              v31 = 0i64;
            v28 = (unsigned int)(v28 + 1);
            v32 = &v31[8 * v28];
            v33 = *(_QWORD *)v32;
            if ( *(_QWORD *)v32 )
              v33 += (__int64)v32;
            if ( v30 )
              v34 = (char *)&this->mConditions.mData + v30;
            else
              v34 = 0i64;
            v35 = &v34[v29];
            if ( v33 )
              v33 -= (__int64)v35;
            *(_QWORD *)v35 = v33;
            v29 += 8i64;
          }
          while ( (unsigned int)v28 < (this->mConditions.mCount & 0x7FFFFFFFu) - 1 );
        }
        v36 = this->mConditions.mData.mOffset;
        if ( v36 )
          v36 += (__int64)&this->mConditions.mData;
        v37 = v36 + 8i64 * ((this->mConditions.mCount & 0x7FFFFFFF) - 1);
        if ( v27 )
          v27 -= v37;
        *(_QWORD *)v37 = v27;
      }
      v1 = (unsigned int)(v1 + 1);
      ++v4;
      v3 += 8i64;
    }
    while ( (unsigned int)v1 < (this->mConditions.mCount & 0x7FFFFFFFu) );
  }
  ConditionGroup::UpdateSignalAndConditionMask(this);
}

// File Line: 217
// RVA: 0x14882D0
__int64 dynamic_initializer_for__gOrCondition__()
{
  gOrCondition.mBreakPoint = 0;
  gOrCondition.vfptr = (Expression::IMemberMapVtbl *)&ORCondition::`vftable;
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gOrCondition__);
}

// File Line: 218
// RVA: 0x1488290
__int64 dynamic_initializer_for__gNotCondition__()
{
  gNotCondition.mBreakPoint = 0;
  gNotCondition.vfptr = (Expression::IMemberMapVtbl *)&NotCondition::`vftable;
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gNotCondition__);
}

// File Line: 237
// RVA: 0x26F9B0
bool __fastcall ConditionGroup::Match(ConditionGroup *this, ActionContext *context)
{
  unsigned __int64 mSignalMask; // rax
  int v6; // ebx
  bool v7; // dl
  char *v8; // r14
  __int64 v9; // rdi
  __int64 v10; // r8
  int v11; // eax
  char v12; // al

  mSignalMask = this->mSignalMask;
  if ( mSignalMask != -1i64 && (mSignalMask & context->mSignals) == 0 && !ActionNode::sEnableNodeBreakPoints )
    return 0;
  v6 = 1;
  v7 = 1;
  v8 = (char *)&this->mConditions.mData + this->mConditions.mData.mOffset;
  v9 = 0i64;
  while ( (unsigned int)v9 < (this->mConditions.mCount & 0x7FFFFFFFu) )
  {
    v10 = (__int64)&v8[8 * v9 + *(_QWORD *)&v8[8 * v9]];
    v11 = *(_DWORD *)v10 == LODWORD(gOrCondition.vfptr) ? 4 : (*(_DWORD *)v10 == LODWORD(gNotCondition.vfptr)) + 1;
    if ( !v7 && v11 != 4 && (v6 & 0xC) == 0 )
      break;
    if ( v11 == 1 )
    {
      if ( !v7 || (v6 & 0xC) == 0 )
      {
        v12 = (*(__int64 (__fastcall **)(char *, ActionContext *))(*(_QWORD *)v10 + 80i64))(
                &v8[8 * v9 + *(_QWORD *)&v8[8 * v9]],
                context);
        v7 = v12;
        if ( (v6 & 0xA) != 0 )
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
  unsigned __int64 v1; // rdi
  int v2; // ebp
  unsigned __int64 v4; // rbx
  char *v5; // r12
  int v6; // esi
  unsigned int v7; // r15d
  __int64 v8; // r14
  int v9; // eax
  __int64 v10; // rax
  __int64 v11; // rax
  __int64 v12; // r9
  unsigned __int64 v13; // rax
  int i; // r8d
  unsigned __int64 v15; // rcx
  int j; // edx
  unsigned __int64 v17; // rcx
  int k; // edx
  unsigned __int64 m; // rcx

  v1 = -1i64;
  v2 = 0;
  v4 = -1i64;
  v5 = (char *)&this->mConditions.mData + this->mConditions.mData.mOffset;
  v6 = 1;
  v7 = 0;
  if ( (this->mConditions.mCount & 0x7FFFFFFF) == 0 )
    goto LABEL_34;
  do
  {
    v8 = (__int64)&v5[8 * v7 + *(_QWORD *)&v5[8 * v7]];
    v9 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v8 + 88i64))(v8);
    switch ( v9 )
    {
      case 1:
        v10 = *(_QWORD *)v8;
        if ( (v6 & 0xA) != 0 )
          v11 = (*(__int64 (__fastcall **)(__int64))(v10 + 104))(v8);
        else
          v11 = (*(__int64 (__fastcall **)(__int64))(v10 + 96))(v8);
        v12 = v11;
        if ( (v6 & 0xC) != 0 )
        {
          v4 |= v11;
          v6 = 1;
        }
        else if ( v1 == -1i64 )
        {
          v1 = v4;
          v6 = 1;
          v4 = v11;
        }
        else
        {
          if ( v4 != -1i64 )
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
  while ( v7 < (this->mConditions.mCount & 0x7FFFFFFFu) );
  if ( v1 == -1i64 )
  {
LABEL_34:
    this->mSignalMask = v4;
  }
  else
  {
    if ( v4 != -1i64 )
    {
      v17 = v1;
      for ( k = 0; v17; v17 &= v17 - 1 )
        ++k;
      for ( m = v4; m; m &= m - 1 )
        ++v2;
      if ( k > v2 )
        v1 = v4;
    }
    this->mSignalMask = v1;
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

