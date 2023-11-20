// File Line: 480
// RVA: 0x10CB20
bool __fastcall APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol>>::append(APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol> > *this, SSMethodBase *elem, unsigned int *insert_pos_p)
{
  unsigned int v3; // er11
  unsigned int *v4; // r12
  SSMethodBase *v5; // r13
  APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol> > *v6; // rsi
  SSMethodBase **v7; // r14
  unsigned int v8; // er10
  signed __int64 v9; // rbx
  SSMethodBase **v10; // r9
  signed __int64 v11; // rax
  unsigned int v12; // edx
  _BOOL8 v13; // rcx
  _BOOL8 v14; // rdx
  signed __int64 v15; // rbx
  char v16; // bp
  SSMethodBase **v17; // r15
  unsigned __int64 v18; // rax
  SSMethodBase **v19; // rax
  signed __int64 v20; // r14

  v3 = this->i_count;
  v4 = insert_pos_p;
  v5 = elem;
  v6 = this;
  if ( this->i_count )
  {
    v7 = this->i_array_p;
    v8 = elem->i_name.i_uid;
    v9 = (signed __int64)&v7[v3 - 1];
    v10 = this->i_array_p;
    while ( 1 )
    {
      while ( 1 )
      {
        v11 = (signed __int64)&v10[(v9 - (signed __int64)v10) >> 4];
        v12 = *(_DWORD *)(*(_QWORD *)v11 + 8i64);
        if ( v8 < v12 )
          break;
        v13 = v8 == v12;
        v14 = v8 != v12;
        if ( 1 - v13 < 0 )
          break;
        if ( v14 <= 0 )
        {
          v16 = 1;
          LODWORD(v15) = (v11 - (signed __int64)v7) >> 3;
          goto LABEL_15;
        }
        if ( v9 == v11 )
        {
          v15 = (v9 - (signed __int64)v7 + 8) >> 3;
          goto LABEL_14;
        }
        v10 = (SSMethodBase **)(v11 + 8);
      }
      if ( v10 == (SSMethodBase **)v11 )
        break;
      v9 = v11 - 8;
    }
    LODWORD(v15) = (v11 - (signed __int64)v7) >> 3;
  }
  else
  {
    LODWORD(v15) = 0;
  }
LABEL_14:
  v16 = 0;
LABEL_15:
  if ( v6->i_size >= v3 + 1 )
  {
    v20 = (unsigned int)v15;
    memmove(&v6->i_array_p[v20 + 1], &v6->i_array_p[v20], 8i64 * (v3 - (unsigned int)v15));
  }
  else
  {
    v17 = v6->i_array_p;
    if ( v3 == -1 )
      LODWORD(v18) = 0;
    else
      v18 = (unsigned __int64)AMemory::c_req_byte_size_func(8 * (v3 & 0xFFFFFFFC) + 32) >> 3;
    v6->i_size = v18;
    v19 = APArrayBase<SSMethodBase>::alloc_array(v18);
    v6->i_array_p = v19;
    v20 = (unsigned int)v15;
    memmove(v19, v17, 8i64 * (unsigned int)v15);
    memmove(&v6->i_array_p[v20 + 1], &v17[v20], 8i64 * (unsigned int)(v6->i_count - v15));
    AMemory::c_free_func(v17);
  }
  v6->i_array_p[v20] = v5;
  ++v6->i_count;
  if ( v4 )
    *v4 = v15;
  return v16 == 0;
}

// File Line: 525
// RVA: 0x10CED0
bool __fastcall APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol>>::append_absent(APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol> > *this, SSTypedName *elem, unsigned int *insert_pos_p)
{
  unsigned int *v3; // r15
  SSTypedName *v4; // rbp
  APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol> > *v5; // r14
  SSTypedName **v6; // r11
  unsigned int v7; // er10
  signed __int64 v8; // rbx
  SSTypedName **v9; // r9
  SSTypedName **v10; // rax
  unsigned int v11; // edx
  _BOOL8 v12; // rcx
  _BOOL8 v13; // rdx
  signed __int64 v14; // rbx
  char v15; // di

  v3 = insert_pos_p;
  v4 = elem;
  v5 = this;
  if ( this->i_count )
  {
    v6 = this->i_array_p;
    v7 = elem->i_name.i_uid;
    v8 = (signed __int64)&v6[this->i_count - 1];
    v9 = this->i_array_p;
    while ( 1 )
    {
      while ( 1 )
      {
        v10 = &v9[(v8 - (signed __int64)v9) >> 4];
        v11 = (*v10)->i_name.i_uid;
        if ( v7 < v11 )
          break;
        v12 = v7 == v11;
        v13 = v7 != v11;
        if ( 1 - v12 < 0 )
          break;
        if ( v13 <= 0 )
        {
          v15 = 1;
          LODWORD(v14) = v10 - v6;
          goto LABEL_15;
        }
        if ( (SSTypedName **)v8 == v10 )
        {
          v14 = (v8 - (signed __int64)v6 + 8) >> 3;
          goto LABEL_14;
        }
        v9 = v10 + 1;
      }
      if ( v9 == v10 )
        break;
      v8 = (signed __int64)(v10 - 1);
    }
    LODWORD(v14) = v10 - v6;
  }
  else
  {
    LODWORD(v14) = 0;
  }
LABEL_14:
  v15 = 0;
  APSizedArrayBase<SSTypedName>::insert((APSizedArrayBase<SSTypedName> *)&v5->i_count, v4, v14);
LABEL_15:
  if ( v3 )
    *v3 = v14;
  return v15 == 0;
}

// File Line: 640
// RVA: 0x10D430
void __fastcall APSorted<SSTypedData,ASymbol,ACompareLogical<ASymbol>>::append_all(APSorted<SSTypedData,ASymbol,ACompareLogical<ASymbol> > *this, APSorted<SSTypedData,ASymbol,ACompareLogical<ASymbol> > *sorted)
{
  unsigned int v2; // edi
  APSorted<SSTypedData,ASymbol,ACompareLogical<ASymbol> > *v3; // rbx
  APSorted<SSTypedData,ASymbol,ACompareLogical<ASymbol> > *v4; // rsi
  unsigned int v5; // eax

  v2 = sorted->i_count;
  v3 = sorted;
  v4 = this;
  APSizedArrayBase<SSTypedData>::ensure_size(
    (APSizedArrayBase<SSTypedData> *)&this->i_count,
    sorted->i_count + this->i_count);
  memmove(&v4->i_array_p[v4->i_count], v3->i_array_p, 8i64 * v2);
  v4->i_count += v2;
  v5 = v4->i_count;
  if ( v4->i_count != v2 && v5 > 1 )
    qsort(v4->i_array_p, v5, 8ui64, APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol>>::sort_compare);
}

// File Line: 748
// RVA: 0x10E320
SSMethodBase *__fastcall APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol>>::append_replace(APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol> > *this, SSMethodBase *elem, unsigned int *insert_pos_p)
{
  SSMethodBase *v3; // rdi
  unsigned int *v4; // rsi
  SSMethodBase *v5; // r11
  APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol> > *v6; // r14
  SSMethodBase **v7; // r10
  unsigned int v8; // er8
  signed __int64 v9; // rbx
  SSMethodBase **v10; // r9
  signed __int64 v11; // rax
  unsigned int v12; // edx
  _BOOL8 v13; // rcx
  _BOOL8 v14; // rdx
  signed __int64 v15; // rbx
  SSMethodBase *result; // rax

  v3 = 0i64;
  v4 = insert_pos_p;
  v5 = elem;
  v6 = this;
  if ( this->i_count )
  {
    v7 = this->i_array_p;
    v8 = elem->i_name.i_uid;
    v9 = (signed __int64)&v7[this->i_count - 1];
    v10 = this->i_array_p;
    while ( 1 )
    {
      while ( 1 )
      {
        v11 = (signed __int64)&v10[(v9 - (signed __int64)v10) >> 4];
        v12 = *(_DWORD *)(*(_QWORD *)v11 + 8i64);
        if ( v8 < v12 )
          break;
        v13 = v8 == v12;
        v14 = v8 != v12;
        if ( 1 - v13 < 0 )
          break;
        if ( v14 <= 0 )
        {
          LODWORD(v15) = (v11 - (signed __int64)v7) >> 3;
          v3 = v7[(unsigned int)v15];
          v7[(unsigned int)v15] = v5;
          goto LABEL_15;
        }
        if ( v9 == v11 )
        {
          v15 = (v9 - (signed __int64)v7 + 8) >> 3;
          goto LABEL_14;
        }
        v10 = (SSMethodBase **)(v11 + 8);
      }
      if ( v10 == (SSMethodBase **)v11 )
        break;
      v9 = v11 - 8;
    }
    LODWORD(v15) = (v11 - (signed __int64)v7) >> 3;
  }
  else
  {
    LODWORD(v15) = 0;
  }
LABEL_14:
  APSizedArrayBase<SSMethodBase>::insert((APSizedArrayBase<SSMethodBase> *)&v6->i_count, v5, v15);
LABEL_15:
  result = v3;
  if ( v4 )
    *v4 = v15;
  return result;
}

// File Line: 970
// RVA: 0x1160D0
__int64 __fastcall APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol>>::free_all(APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol> > *this, ASymbol *keys_p, unsigned int key_count, unsigned int start_pos, unsigned int end_pos)
{
  __int64 v5; // r12
  ASymbol *v6; // rsi
  APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol> > *v7; // r14
  unsigned int v8; // ebp
  ASymbol *v9; // r15
  unsigned int v10; // edi
  unsigned int v11; // ecx
  unsigned int v12; // er11
  SSTypedName **v13; // rbx
  signed __int64 v14; // rdx
  signed __int64 v15; // r9
  unsigned int v16; // er10
  char *v17; // rax
  unsigned int v18; // er8
  _BOOL8 v19; // r8
  signed __int64 v20; // rax
  SSTypedName **v21; // rcx
  SSTypedName *v22; // rbx
  SSClassDescBase *v23; // rcx

  v5 = start_pos;
  v6 = keys_p;
  v7 = this;
  v8 = 0;
  if ( this->i_count )
  {
    v9 = &keys_p[key_count];
    v10 = end_pos;
    if ( end_pos == -1 )
      v10 = this->i_count - 1;
    if ( keys_p < v9 )
    {
      do
      {
        v11 = v10;
        v12 = v7->i_count;
        if ( v7->i_count )
        {
          if ( v10 == -1 )
            v11 = v12 - 1;
          v13 = v7->i_array_p;
          v14 = (signed __int64)&v13[v5];
          v15 = (signed __int64)&v13[v11];
          v16 = v6->i_uid;
          while ( 1 )
          {
            while ( 1 )
            {
              v17 = (char *)(v14 + 8 * ((v15 - v14) >> 4));
              v18 = **(_DWORD **)v17;
              if ( v16 >= v18 )
              {
                v19 = v16 != v18;
                if ( v19 >= 0 )
                  break;
              }
              if ( (char *)v14 == v17 )
                goto LABEL_21;
              v15 = (signed __int64)(v17 - 8);
            }
            if ( v19 <= 0 )
              break;
            if ( (char *)v15 == v17 )
              goto LABEL_21;
            v14 = (signed __int64)(v17 + 8);
          }
          v20 = (v17 - (char *)v13) >> 3;
          v21 = &v13[(unsigned int)v20];
          v22 = *v21;
          v7->i_count = v12 - 1;
          memmove(v21, v21 + 1, 8i64 * (v12 - 1 - (unsigned int)v20));
          if ( v22 )
          {
            v23 = v22->i_type_p.i_obj_p;
            if ( v23 )
              (*(void (__cdecl **)(SSClassDescBase *))&v23->vfptr->gap8[8])(v23);
            AMemory::c_free_func(v22);
          }
          --v10;
          ++v8;
        }
LABEL_21:
        ++v6;
      }
      while ( v6 < v9 );
    }
  }
  return v8;
}

// File Line: 1460
// RVA: 0x13BC70
__int64 __fastcall APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol>>::remove_all_all(APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol> > *this, APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol> > *sorted, unsigned int start_pos, unsigned int end_pos)
{
  APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol> > *v4; // r15
  unsigned int v5; // ecx
  unsigned int v6; // ebp
  int v7; // esi
  __int64 v8; // rax
  ASymbol **v9; // r14
  unsigned __int64 v10; // r13
  ASymbol *v11; // r12
  unsigned int v12; // ebx
  unsigned int v13; // edi
  SSTypedName **v14; // r9
  __int64 v15; // r10
  unsigned __int64 v16; // rdx
  SSTypedName **v17; // rax
  signed __int64 i; // rbx
  SSTypedName **v19; // rcx
  unsigned int find_pos_p; // [rsp+70h] [rbp+8h]
  unsigned int v22; // [rsp+80h] [rbp+18h]

  v22 = start_pos;
  v4 = this;
  v5 = this->i_count;
  v6 = 0;
  v7 = end_pos;
  if ( !v5 )
    return 0i64;
  v8 = sorted->i_count;
  if ( !(_DWORD)v8 )
    return 0i64;
  v9 = (ASymbol **)sorted->i_array_p;
  v10 = (unsigned __int64)&v9[v8];
  if ( end_pos == -1 )
    v7 = v5 - 1;
  if ( (unsigned __int64)v9 >= v10 )
    return 0i64;
  do
  {
    v11 = *v9;
    v12 = 0;
    v13 = v7;
    if ( APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol>>::find(v4, *v9, 1u, &find_pos_p, start_pos, v7) )
    {
      if ( v7 == -1 )
        v13 = v4->i_count - 1;
      v14 = v4->i_array_p;
      v15 = find_pos_p;
      v16 = (unsigned __int64)&v14[v13];
      v17 = &v14[find_pos_p + 1];
      for ( i = (signed __int64)&v14[find_pos_p]; (unsigned __int64)v17 <= v16; ++v17 )
      {
        if ( v11->i_uid != (*v17)->i_name.i_uid )
          break;
        i = (signed __int64)v17;
      }
      v19 = &v14[find_pos_p];
      v12 = (unsigned __int64)((i - (signed __int64)v14) >> 3) - find_pos_p + 1;
      v4->i_count -= v12;
      memmove(v19, &v14[v15 + v12], 8i64 * (unsigned int)(v4->i_count - v15));
    }
    start_pos = v22;
    ++v9;
    v7 -= v12;
    v6 += v12;
  }
  while ( (unsigned __int64)v9 < v10 );
  return v6;
}

// File Line: 1593
// RVA: 0x114AB0
bool __fastcall APSorted<SSClassUnion,SSClassUnion,ACompareLogical<SSClassUnion>>::find(APSorted<SSClassUnion,SSClassUnion,ACompareLogical<SSClassUnion> > *this, SSClassUnion *key, unsigned int instance, unsigned int *find_pos_p, unsigned int start_pos, unsigned int end_pos)
{
  SSClassUnion *v6; // r13
  unsigned int v7; // er10
  SSClassUnion **v8; // rdx
  SSClassUnion **first_p; // r12
  SSClassUnion **last_p; // r15
  SSClassUnion **v11; // rsi
  SSClassUnion *v12; // r14
  __int64 v13; // rcx
  unsigned int v14; // edx
  signed int v15; // eax
  SSClassDescBase **v16; // rbx
  SSClassDescBase **v17; // rdi
  unsigned __int64 v18; // rbp
  __int64 v19; // rax
  unsigned int v20; // edx
  signed int v21; // ecx
  SSClassDescBase **v22; // rbx
  SSClassDescBase **v23; // rdi
  unsigned __int64 v24; // rbp
  _BOOL8 v25; // rcx
  bool result; // al
  APSorted<SSClassUnion,SSClassUnion,ACompareLogical<SSClassUnion> > *v27; // rax
  signed __int64 v28; // rsi
  APSorted<SSClassUnion,SSClassUnion,ACompareLogical<SSClassUnion> > *v29; // [rsp+70h] [rbp+8h]
  unsigned int instancea; // [rsp+80h] [rbp+18h]
  unsigned int *v31; // [rsp+88h] [rbp+20h]

  v31 = find_pos_p;
  instancea = instance;
  v29 = this;
  v6 = key;
  if ( this->i_count )
  {
    v7 = end_pos;
    if ( end_pos == -1 )
      v7 = this->i_count - 1;
    v8 = this->i_array_p;
    first_p = &v8[start_pos];
    last_p = &v8[v7];
    while ( 1 )
    {
      v11 = &first_p[((char *)last_p - (char *)first_p) >> 4];
      v12 = *v11;
      if ( v6 != *v11 )
        break;
      v21 = 0;
LABEL_25:
      v25 = v21 != 0;
      if ( v25 >= 0 )
      {
        if ( v25 <= 0 )
        {
          v27 = v29;
          v28 = v11 - v29->i_array_p;
          LODWORD(v29) = v28;
          if ( instancea )
          {
            result = APSorted<SSClassUnion,SSClassUnion,ACompareLogical<SSClassUnion>>::find_instance(
                       v27,
                       v6,
                       instancea,
                       (unsigned int *)&v29,
                       first_p,
                       last_p);
            LODWORD(v28) = (_DWORD)v29;
          }
          else
          {
            result = 1;
          }
          if ( v31 )
            *v31 = v28;
          return result;
        }
        if ( last_p == v11 )
        {
          if ( v31 )
            *v31 = ((char *)last_p - (char *)v29->i_array_p + 8) >> 3;
          return 0;
        }
        first_p = v11 + 1;
      }
      else
      {
LABEL_26:
        if ( first_p == v11 )
        {
          if ( v31 )
            *v31 = v11 - v29->i_array_p;
          return 0;
        }
        last_p = v11 - 1;
      }
    }
    v13 = v6->i_union.i_count;
    v14 = v12->i_union.i_count;
    if ( (_DWORD)v13 == v14 )
    {
      v16 = (SSClassDescBase **)v6->i_union.i_array_p;
      v17 = (SSClassDescBase **)v12->i_union.i_array_p;
      v18 = (unsigned __int64)&v16[v13];
      if ( (unsigned __int64)v16 >= v18 )
      {
LABEL_15:
        v19 = v6->i_union.i_count;
        v20 = v12->i_union.i_count;
        if ( (_DWORD)v19 == v20 )
        {
          v22 = (SSClassDescBase **)v6->i_union.i_array_p;
          v23 = (SSClassDescBase **)v12->i_union.i_array_p;
          v24 = (unsigned __int64)&v22[v19];
          if ( (unsigned __int64)v22 >= v24 )
          {
LABEL_22:
            v21 = 0;
          }
          else
          {
            while ( 1 )
            {
              v21 = SSClassDescBase::compare(*v22, *v23, (__int64)v22);
              if ( v21 )
                break;
              ++v22;
              ++v23;
              if ( (unsigned __int64)v22 >= v24 )
                goto LABEL_22;
            }
          }
        }
        else
        {
          v21 = 1;
          if ( (unsigned int)v19 < v20 )
            v21 = -1;
        }
        goto LABEL_25;
      }
      while ( 1 )
      {
        v15 = SSClassDescBase::compare(*v16, *v17, (__int64)v16);
        if ( v15 )
          break;
        ++v16;
        ++v17;
        if ( (unsigned __int64)v16 >= v18 )
          goto LABEL_15;
      }
    }
    else
    {
      v15 = 1;
      if ( (unsigned int)v13 < v14 )
        v15 = -1;
    }
    if ( v15 == -1 )
      goto LABEL_26;
    goto LABEL_15;
  }
  if ( find_pos_p )
    *find_pos_p = 0;
  return 0;
}

// File Line: 1703
// RVA: 0x115330
bool __fastcall APSorted<SSActor,ASymbol,ACompareLogical<ASymbol>>::find_elem(APSorted<SSActor,ASymbol,ACompareLogical<ASymbol> > *this, SSActor *elem, unsigned int *find_pos_p, unsigned int start_pos, unsigned int end_pos)
{
  unsigned int v5; // eax
  unsigned int *v6; // rsi
  SSActor *v7; // rdi
  APSorted<SSActor,ASymbol,ACompareLogical<ASymbol> > *v8; // r11
  unsigned int v9; // ebx
  unsigned int v10; // ecx
  SSActor **v11; // r11
  __int64 v12; // rax
  unsigned int v13; // er9
  unsigned __int64 v14; // rdx
  signed __int64 v15; // r10
  signed __int64 v16; // rcx
  unsigned int v17; // er8
  _BOOL8 v18; // r8
  unsigned __int64 v19; // r10
  unsigned __int64 v20; // r8
  unsigned __int64 i; // rcx
  signed __int64 v22; // rdx
  bool v23; // al

  v5 = this->i_count;
  v6 = find_pos_p;
  v7 = elem;
  v8 = this;
  if ( this->i_count )
  {
    v9 = end_pos;
    if ( end_pos == -1 )
      v9 = v5 - 1;
    v10 = v9;
    if ( v9 == -1 )
      v10 = v5 - 1;
    v11 = v8->i_array_p;
    v12 = start_pos;
    v13 = elem->i_name.i_uid;
    v14 = (unsigned __int64)&v11[v12];
    v15 = (signed __int64)&v11[v10];
    while ( 1 )
    {
      while ( 1 )
      {
        v16 = v14 + 8 * ((signed __int64)(v15 - v14) >> 4);
        v17 = *(_DWORD *)(*(_QWORD *)v16 + 72i64);
        if ( v13 >= v17 )
        {
          v18 = v13 != v17;
          if ( v18 >= 0 )
            break;
        }
        if ( v14 == v16 )
          goto LABEL_24;
        v15 = v16 - 8;
      }
      if ( v18 <= 0 )
        break;
      if ( v15 == v16 )
        goto LABEL_24;
      v14 = v16 + 8;
    }
    v19 = (unsigned __int64)&v11[(unsigned int)((v16 - (signed __int64)v11) >> 3)];
    v20 = v19;
    for ( i = v19 - 8; i >= v14; i -= 8i64 )
    {
      if ( v13 != *(_DWORD *)(*(_QWORD *)i + 72i64) )
        break;
      v20 = i;
    }
    v22 = (signed __int64)(v20 - (_QWORD)v11) >> 3;
    if ( v20 <= v19 )
      v23 = 1;
    else
      v23 = v13 == *(_DWORD *)(*(_QWORD *)v20 + 72i64);
    if ( !v23 )
    {
LABEL_24:
      LOBYTE(v5) = 0;
      return v5;
    }
    while ( v11[(unsigned int)v22] != v7 )
    {
      v22 = (unsigned int)(v22 + 1);
      if ( (unsigned int)v22 > v9 || v13 != v11[v22]->i_name.i_uid )
        goto LABEL_24;
    }
    if ( v6 )
      *v6 = v22;
    LOBYTE(v5) = 1;
  }
  return v5;
}

// File Line: 1763
// RVA: 0x117330
SSTypedName *__fastcall APSorted<SSData,ASymbol,ACompareLogical<ASymbol>>::get(APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol> > *this, ASymbol *key)
{
  __int64 v2; // rax
  SSTypedName **v3; // r8
  unsigned int v4; // er10
  signed __int64 v5; // r9
  SSTypedName **v6; // rax
  unsigned int v7; // edx
  _BOOL8 v8; // rdx

  v2 = this->i_count;
  if ( (_DWORD)v2 )
  {
    v3 = this->i_array_p;
    v4 = key->i_uid;
    v5 = (signed __int64)&v3[v2 - 1];
    while ( 1 )
    {
      v6 = &v3[(v5 - (signed __int64)v3) >> 4];
      v7 = (*v6)->i_name.i_uid;
      if ( v4 < v7 )
        goto LABEL_14;
      v8 = v4 != v7;
      if ( !v8 )
        return *v6;
      if ( v8 < 0 )
      {
LABEL_14:
        if ( v3 == v6 )
          return 0i64;
        v5 = (signed __int64)(v6 - 1);
      }
      else
      {
        if ( (SSTypedName **)v5 == v6 )
          return 0i64;
        v3 = v6 + 1;
      }
    }
  }
  return 0i64;
}

// File Line: 2123
// RVA: 0x224F00
bool __fastcall APSorted<AMemoryInfo,AMemoryInfo,ACompareLogicalReverse<AMemoryInfo>>::find_instance(APSorted<AMemoryInfo,AMemoryInfo,ACompareLogicalReverse<AMemoryInfo> > *this, AMemoryInfo *key, unsigned int instance, unsigned int *find_pos_p, AMemoryInfo **first_p, AMemoryInfo **last_p)
{
  __int64 v6; // r10
  AMemoryInfo **v7; // rax
  unsigned int v8; // er12
  unsigned __int64 v9; // r13
  AMemoryInfo *v10; // rsi
  APSorted<AMemoryInfo,AMemoryInfo,ACompareLogicalReverse<AMemoryInfo> > *v11; // r8
  signed __int64 v12; // r14
  AMemoryInfo **v13; // rdi
  AMemoryInfo *v14; // rbp
  unsigned int v15; // ebx
  AMemoryInfo **v16; // rdx
  AMemoryInfo **v18; // rbx
  AMemoryInfo *v19; // rbp
  unsigned int v20; // edi
  APSorted<AMemoryInfo,AMemoryInfo,ACompareLogicalReverse<AMemoryInfo> > *v21; // [rsp+60h] [rbp+8h]
  unsigned int *v22; // [rsp+78h] [rbp+20h]

  v22 = find_pos_p;
  v21 = this;
  v6 = *find_pos_p;
  v7 = this->i_array_p;
  v8 = instance;
  v9 = (unsigned __int64)&v7[v6];
  v10 = key;
  v11 = this;
  v12 = (signed __int64)&v7[v6];
  if ( v8 == -1 )
  {
    v18 = (AMemoryInfo **)(v9 + 8);
    if ( v9 + 8 <= (unsigned __int64)last_p )
    {
      while ( 1 )
      {
        v19 = *v18;
        if ( AMemoryInfo::c_sort_type )
        {
          v20 = v10->i_size_dynamic_total_actual
              + AMemory::c_req_byte_size_func(v10->i_size_static) * v10->i_alloc_count;
          if ( v20 != v19->i_size_dynamic_total_actual
                    + AMemory::c_req_byte_size_func(v19->i_size_static) * v19->i_alloc_count
            || v10->i_alloc_count != v19->i_alloc_count )
          {
LABEL_19:
            find_pos_p = v22;
            v11 = v21;
            break;
          }
        }
        else if ( v10->i_type_id != v19->i_type_id )
        {
          goto LABEL_19;
        }
        v12 = (signed __int64)v18;
        ++v18;
        if ( v18 > last_p )
          goto LABEL_19;
      }
    }
    *find_pos_p = (signed __int64)(v12 - (unsigned __int64)v11->i_array_p) >> 3;
    return 1;
  }
  v13 = (AMemoryInfo **)(v9 - 8);
  if ( v9 - 8 < (unsigned __int64)first_p )
    goto LABEL_10;
  do
  {
    v14 = *v13;
    if ( AMemoryInfo::c_sort_type == SortType_id )
    {
      if ( v10->i_type_id != v14->i_type_id )
        break;
      goto LABEL_8;
    }
    v15 = v10->i_size_dynamic_total_actual + AMemory::c_req_byte_size_func(v10->i_size_static) * v10->i_alloc_count;
    if ( v15 != v14->i_size_dynamic_total_actual
              + AMemory::c_req_byte_size_func(v14->i_size_static) * v14->i_alloc_count
      || v10->i_alloc_count != v14->i_alloc_count )
    {
      break;
    }
LABEL_8:
    v12 = (signed __int64)v13;
    --v13;
  }
  while ( v13 >= first_p );
  find_pos_p = v22;
  v11 = v21;
LABEL_10:
  v16 = (AMemoryInfo **)(v12 + 8i64 * (v8 - 1));
  *find_pos_p = (signed __int64)(v12 + 8i64 * (v8 - 1) - (unsigned __int64)v11->i_array_p) >> 3;
  if ( (unsigned __int64)v16 > v9 )
    return AMemoryInfo::operator==(v10, *v16);
  return 1;
}

// File Line: 2210
// RVA: 0x13C920
signed __int64 __fastcall APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol>>::sort_compare(const void *lhs_p, const void *rhs_p)
{
  unsigned int *v2; // r11
  __int64 v3; // r8
  unsigned int v4; // eax
  unsigned int v5; // er9

  v2 = *(unsigned int **)lhs_p;
  v3 = 0i64;
  v4 = **(_DWORD **)lhs_p;
  v5 = **(_DWORD **)rhs_p;
  LODWORD(rhs_p) = 1;
  if ( v4 < v5 || (v4 != v5) <= 0i64 )
  {
    if ( *v2 < v5 )
      return 0xFFFFFFFFi64;
    LOBYTE(v3) = *v2 == v5;
    rhs_p = (const void *)((1 - v3) >> 63);
  }
  return (unsigned int)rhs_p;
}

