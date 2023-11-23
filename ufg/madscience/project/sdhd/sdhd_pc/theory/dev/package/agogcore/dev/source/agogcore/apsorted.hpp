// File Line: 480
// RVA: 0x10CB20
bool __fastcall APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol>>::append(
        APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol> > *this,
        SSMethodBase *elem,
        unsigned int *insert_pos_p)
{
  unsigned int i_count; // r11d
  SSMethodBase **i_array_p; // r14
  unsigned int i_uid; // r10d
  SSMethodBase **v9; // rbx
  SSMethodBase **v10; // r9
  SSMethodBase **v11; // rax
  unsigned int v12; // edx
  _BOOL8 v13; // rcx
  _BOOL8 v14; // rdx
  __int64 v15; // rbx
  char v16; // bp
  SSMethodBase **v17; // r15
  unsigned __int64 v18; // rax
  SSMethodBase **v19; // rax
  __int64 v20; // r14

  i_count = this->i_count;
  if ( this->i_count )
  {
    i_array_p = this->i_array_p;
    i_uid = elem->i_name.i_uid;
    v9 = &i_array_p[i_count - 1];
    v10 = i_array_p;
    while ( 1 )
    {
      while ( 1 )
      {
        v11 = &v10[((char *)v9 - (char *)v10) >> 4];
        v12 = (*v11)->i_name.i_uid;
        if ( i_uid < v12 )
          break;
        v13 = i_uid == v12;
        v14 = i_uid != v12;
        if ( 1 - v13 < 0 )
          break;
        if ( v14 <= 0 )
        {
          v16 = 1;
          LODWORD(v15) = v11 - i_array_p;
          goto LABEL_15;
        }
        if ( v9 == v11 )
        {
          v15 = ((char *)v9 - (char *)i_array_p + 8) >> 3;
          goto LABEL_14;
        }
        v10 = v11 + 1;
      }
      if ( v10 == v11 )
        break;
      v9 = v11 - 1;
    }
    LODWORD(v15) = v11 - i_array_p;
  }
  else
  {
    LODWORD(v15) = 0;
  }
LABEL_14:
  v16 = 0;
LABEL_15:
  if ( this->i_size >= i_count + 1 )
  {
    v20 = (unsigned int)v15;
    memmove(&this->i_array_p[v20 + 1], &this->i_array_p[v20], 8i64 * (i_count - (unsigned int)v15));
  }
  else
  {
    v17 = this->i_array_p;
    if ( i_count == -1 )
      LODWORD(v18) = 0;
    else
      v18 = (unsigned __int64)AMemory::c_req_byte_size_func(8 * (i_count & 0xFFFFFFFC) + 32) >> 3;
    this->i_size = v18;
    v19 = APArrayBase<SSMethodBase>::alloc_array(v18);
    this->i_array_p = v19;
    v20 = (unsigned int)v15;
    memmove(v19, v17, v20 * 8);
    memmove(&this->i_array_p[v20 + 1], &v17[v20], 8i64 * (unsigned int)(this->i_count - v15));
    AMemory::c_free_func(v17);
  }
  this->i_array_p[v20] = elem;
  ++this->i_count;
  if ( insert_pos_p )
    *insert_pos_p = v15;
  return v16 == 0;
}

// File Line: 525
// RVA: 0x10CED0
bool __fastcall APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol>>::append_absent(
        APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol> > *this,
        SSTypedName *elem,
        unsigned int *insert_pos_p)
{
  SSTypedName **i_array_p; // r11
  unsigned int i_uid; // r10d
  SSTypedName **v8; // rbx
  SSTypedName **v9; // r9
  char *v10; // rax
  unsigned int v11; // edx
  _BOOL8 v12; // rcx
  _BOOL8 v13; // rdx
  __int64 v14; // rbx
  char v15; // di

  if ( this->i_count )
  {
    i_array_p = this->i_array_p;
    i_uid = elem->i_name.i_uid;
    v8 = &i_array_p[this->i_count - 1];
    v9 = i_array_p;
    while ( 1 )
    {
      while ( 1 )
      {
        v10 = (char *)&v9[((char *)v8 - (char *)v9) >> 4];
        v11 = **(_DWORD **)v10;
        if ( i_uid < v11 )
          break;
        v12 = i_uid == v11;
        v13 = i_uid != v11;
        if ( 1 - v12 < 0 )
          break;
        if ( v13 <= 0 )
        {
          v15 = 1;
          LODWORD(v14) = (v10 - (char *)i_array_p) >> 3;
          goto LABEL_15;
        }
        if ( v8 == (SSTypedName **)v10 )
        {
          v14 = ((char *)v8 - (char *)i_array_p + 8) >> 3;
          goto LABEL_14;
        }
        v9 = (SSTypedName **)(v10 + 8);
      }
      if ( v9 == (SSTypedName **)v10 )
        break;
      v8 = (SSTypedName **)(v10 - 8);
    }
    LODWORD(v14) = (v10 - (char *)i_array_p) >> 3;
  }
  else
  {
    LODWORD(v14) = 0;
  }
LABEL_14:
  v15 = 0;
  APSizedArrayBase<SSTypedName>::insert(this, elem, v14);
LABEL_15:
  if ( insert_pos_p )
    *insert_pos_p = v14;
  return v15 == 0;
}

// File Line: 640
// RVA: 0x10D430
void __fastcall APSorted<SSTypedData,ASymbol,ACompareLogical<ASymbol>>::append_all(
        APSorted<SSTypedData,ASymbol,ACompareLogical<ASymbol> > *this,
        APSorted<SSTypedData,ASymbol,ACompareLogical<ASymbol> > *sorted)
{
  unsigned int i_count; // edi
  unsigned int v5; // eax

  i_count = sorted->i_count;
  APSizedArrayBase<SSTypedData>::ensure_size(this, sorted->i_count + this->i_count);
  memmove(&this->i_array_p[this->i_count], sorted->i_array_p, 8i64 * i_count);
  this->i_count += i_count;
  v5 = this->i_count;
  if ( this->i_count != i_count && v5 > 1 )
    qsort(this->i_array_p, v5, 8ui64, APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol>>::sort_compare);
}

// File Line: 748
// RVA: 0x10E320
SSMethodBase *__fastcall APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol>>::append_replace(
        APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol> > *this,
        SSMethodBase *elem,
        unsigned int *insert_pos_p)
{
  SSMethodBase *v3; // rdi
  SSMethodBase **i_array_p; // r10
  unsigned int i_uid; // r8d
  SSMethodBase **v9; // rbx
  SSMethodBase **v10; // r9
  SSMethodBase **v11; // rax
  unsigned int v12; // edx
  _BOOL8 v13; // rcx
  _BOOL8 v14; // rdx
  __int64 v15; // rbx
  SSMethodBase *result; // rax

  v3 = 0i64;
  if ( this->i_count )
  {
    i_array_p = this->i_array_p;
    i_uid = elem->i_name.i_uid;
    v9 = &i_array_p[this->i_count - 1];
    v10 = i_array_p;
    while ( 1 )
    {
      while ( 1 )
      {
        v11 = &v10[((char *)v9 - (char *)v10) >> 4];
        v12 = (*v11)->i_name.i_uid;
        if ( i_uid < v12 )
          break;
        v13 = i_uid == v12;
        v14 = i_uid != v12;
        if ( 1 - v13 < 0 )
          break;
        if ( v14 <= 0 )
        {
          LODWORD(v15) = v11 - i_array_p;
          v3 = i_array_p[(unsigned int)v15];
          i_array_p[(unsigned int)v15] = elem;
          goto LABEL_15;
        }
        if ( v9 == v11 )
        {
          v15 = ((char *)v9 - (char *)i_array_p + 8) >> 3;
          goto LABEL_14;
        }
        v10 = v11 + 1;
      }
      if ( v10 == v11 )
        break;
      v9 = v11 - 1;
    }
    LODWORD(v15) = v11 - i_array_p;
  }
  else
  {
    LODWORD(v15) = 0;
  }
LABEL_14:
  APSizedArrayBase<SSMethodBase>::insert(this, elem, v15);
LABEL_15:
  result = v3;
  if ( insert_pos_p )
    *insert_pos_p = v15;
  return result;
}

// File Line: 970
// RVA: 0x1160D0
__int64 __fastcall APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol>>::free_all(
        APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol> > *this,
        ASymbol *keys_p,
        unsigned int key_count,
        unsigned int start_pos,
        unsigned int end_pos)
{
  __int64 v5; // r12
  ASymbol *v6; // rsi
  unsigned int v8; // ebp
  ASymbol *v9; // r15
  unsigned int v10; // edi
  unsigned int v11; // ecx
  unsigned int i_count; // r11d
  SSTypedName **i_array_p; // rbx
  SSTypedName **v14; // rdx
  SSTypedName **v15; // r9
  unsigned int i_uid; // r10d
  char *v17; // rax
  unsigned int v18; // r8d
  __int64 v19; // rax
  SSTypedName **v20; // rcx
  SSTypedName *v21; // rbx
  SSClassDescBase *i_obj_p; // rcx

  v5 = start_pos;
  v6 = keys_p;
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
        i_count = this->i_count;
        if ( this->i_count )
        {
          if ( v10 == -1 )
            v11 = i_count - 1;
          i_array_p = this->i_array_p;
          v14 = &i_array_p[v5];
          v15 = &i_array_p[v11];
          i_uid = v6->i_uid;
          while ( 1 )
          {
            while ( 1 )
            {
              v17 = (char *)&v14[((char *)v15 - (char *)v14) >> 4];
              v18 = **(_DWORD **)v17;
              if ( i_uid >= v18 )
                break;
              if ( v14 == (SSTypedName **)v17 )
                goto LABEL_20;
              v15 = (SSTypedName **)(v17 - 8);
            }
            if ( i_uid == v18 )
              break;
            if ( v15 == (SSTypedName **)v17 )
              goto LABEL_20;
            v14 = (SSTypedName **)(v17 + 8);
          }
          v19 = (v17 - (char *)i_array_p) >> 3;
          v20 = &i_array_p[(unsigned int)v19];
          v21 = *v20;
          this->i_count = i_count - 1;
          memmove(v20, v20 + 1, 8i64 * (i_count - 1 - (unsigned int)v19));
          if ( v21 )
          {
            i_obj_p = v21->i_type_p.i_obj_p;
            if ( i_obj_p )
              (*(void (__fastcall **)(SSClassDescBase *))&i_obj_p->vfptr->gap8[8])(i_obj_p);
            AMemory::c_free_func(v21);
          }
          --v10;
          ++v8;
        }
LABEL_20:
        ++v6;
      }
      while ( v6 < v9 );
    }
  }
  return v8;
}

// File Line: 1460
// RVA: 0x13BC70
__int64 __fastcall APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol>>::remove_all_all(
        APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol> > *this,
        APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol> > *sorted,
        unsigned int start_pos,
        unsigned int end_pos)
{
  unsigned int i_count; // ecx
  unsigned int v6; // ebp
  unsigned int v7; // esi
  __int64 v8; // rax
  ASymbol **i_array_p; // r14
  ASymbol **v10; // r13
  ASymbol *v11; // r12
  unsigned int v12; // ebx
  unsigned int v13; // edi
  SSTypedName **v14; // r9
  __int64 v15; // r10
  SSTypedName **v16; // rdx
  SSTypedName **v17; // rax
  SSTypedName **i; // rbx
  SSTypedName **v19; // rcx
  unsigned int find_pos_p; // [rsp+70h] [rbp+8h] BYREF
  unsigned int v22; // [rsp+80h] [rbp+18h]

  v22 = start_pos;
  i_count = this->i_count;
  v6 = 0;
  v7 = end_pos;
  if ( !i_count )
    return 0i64;
  v8 = sorted->i_count;
  if ( !(_DWORD)v8 )
    return 0i64;
  i_array_p = (ASymbol **)sorted->i_array_p;
  v10 = &i_array_p[v8];
  if ( end_pos == -1 )
    v7 = i_count - 1;
  if ( i_array_p >= v10 )
    return 0i64;
  do
  {
    v11 = *i_array_p;
    v12 = 0;
    v13 = v7;
    if ( APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol>>::find(this, *i_array_p, 1u, &find_pos_p, start_pos, v7) )
    {
      if ( v7 == -1 )
        v13 = this->i_count - 1;
      v14 = this->i_array_p;
      v15 = find_pos_p;
      v16 = &v14[v13];
      v17 = &v14[find_pos_p + 1];
      for ( i = &v14[find_pos_p]; v17 <= v16; ++v17 )
      {
        if ( v11->i_uid != (*v17)->i_name.i_uid )
          break;
        i = v17;
      }
      v19 = &v14[find_pos_p];
      v12 = i - v14 - find_pos_p + 1;
      this->i_count -= v12;
      memmove(v19, &v14[v15] + v12, 8i64 * (unsigned int)(this->i_count - v15));
    }
    start_pos = v22;
    ++i_array_p;
    v7 -= v12;
    v6 += v12;
  }
  while ( i_array_p < v10 );
  return v6;
}

// File Line: 1593
// RVA: 0x114AB0
bool __fastcall APSorted<SSClassUnion,SSClassUnion,ACompareLogical<SSClassUnion>>::find(
        APSorted<SSClassUnion,SSClassUnion,ACompareLogical<SSClassUnion> > *this,
        SSClassUnion *key,
        unsigned int instance,
        unsigned int *find_pos_p,
        unsigned int start_pos,
        unsigned int end_pos)
{
  unsigned int v7; // r10d
  SSClassUnion **i_array_p; // rdx
  SSClassUnion **first_p; // r12
  SSClassUnion **last_p; // r15
  SSClassUnion **v11; // rsi
  SSClassUnion *v12; // r14
  __int64 i_count; // rcx
  unsigned int v14; // edx
  int v15; // eax
  SSClassDescBase **v16; // rbx
  SSClassDescBase **v17; // rdi
  SSClassDescBase **v18; // rbp
  __int64 v19; // rax
  unsigned int v20; // edx
  int v21; // ecx
  SSClassDescBase **v22; // rbx
  SSClassDescBase **v23; // rdi
  SSClassDescBase **v24; // rbp
  _BOOL8 v25; // rcx
  bool result; // al
  APSorted<SSClassUnion,SSClassUnion,ACompareLogical<SSClassUnion> > *v27; // rax
  __int64 v28; // rsi
  APSorted<SSClassUnion,SSClassUnion,ACompareLogical<SSClassUnion> > *v29; // [rsp+70h] [rbp+8h] BYREF
  unsigned int instancea; // [rsp+80h] [rbp+18h]
  unsigned int *v31; // [rsp+88h] [rbp+20h]

  v31 = find_pos_p;
  instancea = instance;
  v29 = this;
  if ( this->i_count )
  {
    v7 = end_pos;
    if ( end_pos == -1 )
      v7 = this->i_count - 1;
    i_array_p = this->i_array_p;
    first_p = &i_array_p[start_pos];
    last_p = &i_array_p[v7];
    while ( 1 )
    {
      v11 = &first_p[((char *)last_p - (char *)first_p) >> 4];
      v12 = *v11;
      if ( key == *v11 )
      {
        v21 = 0;
        goto LABEL_25;
      }
      i_count = key->i_union.i_count;
      v14 = v12->i_union.i_count;
      if ( (_DWORD)i_count == v14 )
      {
        v16 = key->i_union.i_array_p;
        v17 = v12->i_union.i_array_p;
        v18 = &v16[i_count];
        if ( v16 >= v18 )
          goto LABEL_15;
        while ( 1 )
        {
          v15 = SSClassDescBase::compare(*v16, *v17);
          if ( v15 )
            break;
          ++v16;
          ++v17;
          if ( v16 >= v18 )
            goto LABEL_15;
        }
      }
      else
      {
        v15 = 1;
        if ( (unsigned int)i_count < v14 )
          v15 = -1;
      }
      if ( v15 == -1 )
      {
        if ( first_p == v11 )
        {
          if ( v31 )
            *v31 = v11 - v29->i_array_p;
          return 0;
        }
        last_p = v11 - 1;
      }
      else
      {
LABEL_15:
        v19 = key->i_union.i_count;
        v20 = v12->i_union.i_count;
        if ( (_DWORD)v19 == v20 )
        {
          v22 = key->i_union.i_array_p;
          v23 = v12->i_union.i_array_p;
          v24 = &v22[v19];
          if ( v22 >= v24 )
          {
LABEL_22:
            v21 = 0;
          }
          else
          {
            while ( 1 )
            {
              v21 = SSClassDescBase::compare(*v22, *v23);
              if ( v21 )
                break;
              ++v22;
              ++v23;
              if ( v22 >= v24 )
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
LABEL_25:
        v25 = v21 != 0;
        if ( v25 <= 0 )
        {
          v27 = v29;
          v28 = v11 - v29->i_array_p;
          LODWORD(v29) = v28;
          if ( instancea )
          {
            result = APSorted<SSClassUnion,SSClassUnion,ACompareLogical<SSClassUnion>>::find_instance(
                       v27,
                       key,
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
    }
  }
  if ( find_pos_p )
    *find_pos_p = 0;
  return 0;
}

// File Line: 1703
// RVA: 0x115330
bool __fastcall APSorted<SSActor,ASymbol,ACompareLogical<ASymbol>>::find_elem(
        APSorted<SSActor,ASymbol,ACompareLogical<ASymbol> > *this,
        SSActor *elem,
        unsigned int *find_pos_p,
        unsigned int start_pos,
        unsigned int end_pos)
{
  unsigned int i_count; // eax
  unsigned int v9; // ebx
  unsigned int v10; // ecx
  SSActor **i_array_p; // r11
  __int64 v12; // rax
  unsigned int i_uid; // r9d
  SSActor **v14; // rdx
  SSActor **v15; // r10
  SSActor **v16; // rcx
  unsigned int v17; // r8d
  SSActor **v18; // r10
  SSActor **v19; // r8
  SSActor **i; // rcx
  __int64 v21; // rdx

  i_count = this->i_count;
  if ( this->i_count )
  {
    v9 = end_pos;
    if ( end_pos == -1 )
      v9 = i_count - 1;
    v10 = v9;
    if ( v9 == -1 )
      v10 = i_count - 1;
    i_array_p = this->i_array_p;
    v12 = start_pos;
    i_uid = elem->i_name.i_uid;
    v14 = &i_array_p[v12];
    v15 = &i_array_p[v10];
    while ( 1 )
    {
      while ( 1 )
      {
        v16 = &v14[((char *)v15 - (char *)v14) >> 4];
        v17 = (*v16)->i_name.i_uid;
        if ( i_uid >= v17 )
          break;
        if ( v14 == v16 )
          goto LABEL_23;
        v15 = v16 - 1;
      }
      if ( i_uid == v17 )
        break;
      if ( v15 == v16 )
        goto LABEL_23;
      v14 = v16 + 1;
    }
    v18 = &i_array_p[(unsigned int)(v16 - i_array_p)];
    v19 = v18;
    for ( i = v18 - 1; i >= v14; --i )
    {
      if ( i_uid != (*i)->i_name.i_uid )
        break;
      v19 = i;
    }
    v21 = v19 - i_array_p;
    if ( v19 > v18 && i_uid != (*v19)->i_name.i_uid )
    {
LABEL_23:
      LOBYTE(i_count) = 0;
      return i_count;
    }
    while ( i_array_p[(unsigned int)v21] != elem )
    {
      v21 = (unsigned int)(v21 + 1);
      if ( (unsigned int)v21 > v9 || i_uid != i_array_p[v21]->i_name.i_uid )
        goto LABEL_23;
    }
    if ( find_pos_p )
      *find_pos_p = v21;
    LOBYTE(i_count) = 1;
  }
  return i_count;
}

// File Line: 1763
// RVA: 0x117330
SSTypedName *__fastcall APSorted<SSData,ASymbol,ACompareLogical<ASymbol>>::get(
        APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol> > *this,
        ASymbol *key)
{
  __int64 i_count; // rax
  SSTypedName **i_array_p; // r8
  unsigned int i_uid; // r10d
  SSTypedName **v5; // r9
  SSTypedName **v6; // rax
  unsigned int v7; // edx

  i_count = this->i_count;
  if ( !(_DWORD)i_count )
    return 0i64;
  i_array_p = this->i_array_p;
  i_uid = key->i_uid;
  v5 = &i_array_p[i_count - 1];
  while ( 1 )
  {
    while ( 1 )
    {
      v6 = &i_array_p[((char *)v5 - (char *)i_array_p) >> 4];
      v7 = (*v6)->i_name.i_uid;
      if ( i_uid >= v7 )
        break;
      if ( i_array_p == v6 )
        return 0i64;
      v5 = v6 - 1;
    }
    if ( i_uid == v7 )
      break;
    if ( v5 == v6 )
      return 0i64;
    i_array_p = v6 + 1;
  }
  return *v6;
}

// File Line: 2123
// RVA: 0x224F00
bool __fastcall APSorted<AMemoryInfo,AMemoryInfo,ACompareLogicalReverse<AMemoryInfo>>::find_instance(
        APSorted<AMemoryInfo,AMemoryInfo,ACompareLogicalReverse<AMemoryInfo> > *this,
        AMemoryInfo *key,
        unsigned int instance,
        unsigned int *find_pos_p,
        AMemoryInfo **first_p,
        AMemoryInfo **last_p)
{
  AMemoryInfo **v7; // r13
  APSorted<AMemoryInfo,AMemoryInfo,ACompareLogicalReverse<AMemoryInfo> > *v9; // r8
  AMemoryInfo **v10; // r14
  AMemoryInfo **v11; // rdi
  AMemoryInfo *v12; // rbp
  unsigned int v13; // ebx
  AMemoryInfo **v14; // rdx
  AMemoryInfo **v16; // rbx
  AMemoryInfo *v17; // rbp
  unsigned int v18; // edi
  unsigned int *v20; // [rsp+78h] [rbp+20h]

  v20 = find_pos_p;
  v7 = &this->i_array_p[*find_pos_p];
  v9 = this;
  v10 = v7;
  if ( instance == -1 )
  {
    v16 = v7 + 1;
    if ( v7 + 1 <= last_p )
    {
      while ( 1 )
      {
        v17 = *v16;
        if ( AMemoryInfo::c_sort_type )
        {
          v18 = key->i_size_dynamic_total_actual
              + AMemory::c_req_byte_size_func(key->i_size_static) * key->i_alloc_count;
          if ( v18 != v17->i_size_dynamic_total_actual
                    + AMemory::c_req_byte_size_func(v17->i_size_static) * v17->i_alloc_count
            || key->i_alloc_count != v17->i_alloc_count )
          {
LABEL_19:
            find_pos_p = v20;
            v9 = this;
            break;
          }
        }
        else if ( key->i_type_id != v17->i_type_id )
        {
          goto LABEL_19;
        }
        v10 = v16++;
        if ( v16 > last_p )
          goto LABEL_19;
      }
    }
    *find_pos_p = v10 - v9->i_array_p;
    return 1;
  }
  v11 = v7 - 1;
  if ( v7 - 1 < first_p )
    goto LABEL_10;
  do
  {
    v12 = *v11;
    if ( AMemoryInfo::c_sort_type == SortType_id )
    {
      if ( key->i_type_id != v12->i_type_id )
        break;
      goto LABEL_8;
    }
    v13 = key->i_size_dynamic_total_actual + AMemory::c_req_byte_size_func(key->i_size_static) * key->i_alloc_count;
    if ( v13 != v12->i_size_dynamic_total_actual
              + AMemory::c_req_byte_size_func(v12->i_size_static) * v12->i_alloc_count
      || key->i_alloc_count != v12->i_alloc_count )
    {
      break;
    }
LABEL_8:
    v10 = v11--;
  }
  while ( v11 >= first_p );
  find_pos_p = v20;
  v9 = this;
LABEL_10:
  v14 = &v10[instance - 1];
  *find_pos_p = v14 - v9->i_array_p;
  if ( v14 > v7 )
    return AMemoryInfo::operator==(key, *v14);
  return 1;
}

// File Line: 2210
// RVA: 0x13C920
__int64 __fastcall APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol>>::sort_compare(
        unsigned int **lhs_p,
        unsigned int **rhs_p)
{
  unsigned int *v2; // r11
  __int64 v3; // r8
  unsigned int v4; // r9d

  v2 = *lhs_p;
  v3 = 0i64;
  v4 = **rhs_p;
  LODWORD(rhs_p) = 1;
  if ( **lhs_p <= v4 )
  {
    if ( *v2 < v4 )
      return 0xFFFFFFFFi64;
    LOBYTE(v3) = *v2 == v4;
    return (unsigned int)((1 - v3) >> 63);
  }
  return (unsigned int)rhs_p;
}

