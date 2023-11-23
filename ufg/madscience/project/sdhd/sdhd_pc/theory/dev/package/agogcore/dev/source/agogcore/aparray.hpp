// File Line: 298
// RVA: 0x223720
void __fastcall APArray<ASymbol,ASymbol,ACompareLogical<ASymbol>>::~APArray<ASymbol,ASymbol,ACompareLogical<ASymbol>>(
        AVCompactSorted<ASymbol,ASymbol,ACompareLogical<ASymbol> > *this)
{
  AMemory::c_free_func(this->i_array_p);
}

// File Line: 320
// RVA: 0x107A00
APArray<SSInstance,SSInstance,ACompareAddress<SSInstance> > *__fastcall APArray<SSInstance,SSInstance,ACompareAddress<SSInstance>>::operator=(
        APArray<SSInstance,SSInstance,ACompareAddress<SSInstance> > *this,
        APArrayBase<SSInstance> *array)
{
  __int64 i_count; // rdi
  unsigned int v5; // eax
  SSInstance **i_array_p; // rcx

  i_count = array->i_count;
  if ( (unsigned int)i_count > this->i_size )
  {
    AMemory::c_free_func(this->i_array_p);
    v5 = AMemory::c_req_byte_size_func(8 * i_count);
    this->i_size = v5 >> 3;
    this->i_array_p = APArrayBase<SSInstance>::alloc_array(v5 >> 3);
  }
  i_array_p = this->i_array_p;
  this->i_count = i_count;
  memmove(i_array_p, array->i_array_p, 8 * i_count);
  return this;
}

// File Line: 358
// RVA: 0x4CC090
APArray<SSActor,SSActor,ACompareAddress<SSActor> > *__fastcall APArray<SSActor,SSActor,ACompareAddress<SSActor>>::operator=(
        APArray<SSActor,SSActor,ACompareAddress<SSActor> > *this,
        APArrayBase<SSActor> *array)
{
  __int64 i_count; // rdi
  unsigned int v5; // eax
  SSActor **i_array_p; // rcx

  i_count = array->i_count;
  if ( (unsigned int)i_count > this->i_size )
  {
    AMemory::c_free_func(this->i_array_p);
    v5 = AMemory::c_req_byte_size_func(8 * i_count);
    this->i_size = v5 >> 3;
    this->i_array_p = APArrayBase<SSActor>::alloc_array(v5 >> 3);
  }
  i_array_p = this->i_array_p;
  this->i_count = i_count;
  memmove(i_array_p, array->i_array_p, 8 * i_count);
  return this;
}

// File Line: 618
// RVA: 0x10B660
void __fastcall APArray<SSData,ASymbol,ACompareLogical<ASymbol>>::append(
        APArray<SSData,ASymbol,ACompareLogical<ASymbol> > *this,
        SSData *elem)
{
  __int64 i_count; // rdi
  SSData **i_array_p; // rbp
  unsigned __int64 v6; // rax
  SSData **v7; // rax

  i_count = this->i_count;
  if ( this->i_size < (unsigned int)(i_count + 1) )
  {
    i_array_p = this->i_array_p;
    if ( (_DWORD)i_count == -1 )
      LODWORD(v6) = 0;
    else
      v6 = (unsigned __int64)AMemory::c_req_byte_size_func(8 * (i_count & 0xFFFFFFFC) + 32) >> 3;
    this->i_size = v6;
    v7 = APArrayBase<SSData>::alloc_array(v6);
    this->i_array_p = v7;
    memmove(v7, i_array_p, 8 * i_count);
    AMemory::c_free_func(i_array_p);
  }
  this->i_array_p[i_count] = elem;
  ++this->i_count;
}

// File Line: 688
// RVA: 0x10D200
void __fastcall APArray<SSInstance,SSInstance,ACompareAddress<SSInstance>>::append_all(
        APArray<SSInstance,SSInstance,ACompareAddress<SSInstance> > *this,
        APArray<SSInstance,SSInstance,ACompareAddress<SSInstance> > *array,
        unsigned int pos,
        unsigned int elem_count)
{
  unsigned int v4; // ebx
  __int64 v5; // rsi

  v4 = elem_count;
  v5 = pos;
  if ( elem_count == -1 )
    v4 = array->i_count - pos;
  if ( v4 )
  {
    APSizedArrayBase<SSInstance>::ensure_size(this, v4 + this->i_count);
    memmove(&this->i_array_p[this->i_count], &array->i_array_p[v5], 8i64 * v4);
    this->i_count += v4;
  }
}

// File Line: 733
// RVA: 0x10D3C0
void __fastcall APArray<SSInvokedMethod,SSInvokedMethod,ACompareAddress<SSInvokedMethod>>::append_all(
        APArray<SSInvokedMethod,SSInvokedMethod,ACompareAddress<SSInvokedMethod> > *this,
        SSInvokedMethod *elems_p,
        unsigned int elem_count)
{
  SSInvokedMethod **v6; // r9
  __int64 v7; // rax

  if ( elem_count )
  {
    APSizedArrayBase<SSInvokedMethod>::ensure_size(this, elem_count + this->i_count);
    v6 = &this->i_array_p[this->i_count];
    v7 = elem_count;
    do
    {
      *v6++ = elems_p++;
      --v7;
    }
    while ( v7 );
    this->i_count += elem_count;
  }
}

// File Line: 1178
// RVA: 0x131150
void __fastcall APArray<SSInstance,SSInstance,ACompareAddress<SSInstance>>::pop_all(
        APArray<SSInstance,SSInstance,ACompareAddress<SSInstance> > *this,
        APArray<SSInstance,SSInstance,ACompareAddress<SSInstance> > *collected_p,
        unsigned int pos,
        unsigned int elem_count)
{
  unsigned int v4; // esi
  __int64 v5; // rbp
  SSInstance **i_array_p; // rcx

  v4 = elem_count;
  v5 = pos;
  if ( elem_count == -1 )
    v4 = this->i_count - pos;
  if ( v4 )
  {
    APSizedArrayBase<SSInstance>::ensure_size(collected_p, v4 + collected_p->i_count);
    memmove(&collected_p->i_array_p[collected_p->i_count], &this->i_array_p[v5], 8i64 * v4);
    collected_p->i_count += v4;
    i_array_p = this->i_array_p;
    this->i_count -= v4;
    memmove(&i_array_p[v5], &i_array_p[v4] + v5, 8i64 * (unsigned int)(this->i_count - v5));
  }
}

// File Line: 1587
// RVA: 0x13C260
void __fastcall APArray<SSInstance,SSInstance,ACompareAddress<SSInstance>>::set_all(
        APArray<SSInstance,SSInstance,ACompareAddress<SSInstance> > *this,
        SSInstance *elem_p,
        unsigned int pos,
        unsigned int elem_count)
{
  unsigned int v4; // ebx
  __int64 v5; // r14
  unsigned int v8; // ebp
  SSInstance **i_array_p; // rax

  v4 = elem_count;
  v5 = pos;
  if ( elem_count == -1 )
    v4 = this->i_count - pos;
  if ( v4 )
  {
    v8 = pos + v4;
    APSizedArrayBase<SSInstance>::ensure_size(this, pos + v4);
    i_array_p = this->i_array_p;
    if ( this->i_count < v8 )
      this->i_count = v8;
    do
    {
      i_array_p[v5] = elem_p;
      --v4;
    }
    while ( v4 );
  }
}

// File Line: 2381
// RVA: 0x106880
void __fastcall APArrayFree<SSInvokeBase,SSInvokeBase,ACompareAddress<SSInvokeBase>>::~APArrayFree<SSInvokeBase,SSInvokeBase,ACompareAddress<SSInvokeBase>>(
        APArrayFree<SSInvokeBase,SSInvokeBase,ACompareAddress<SSInvokeBase> > *this)
{
  SSInvokeBase **i_array_p; // rbx
  SSInvokeBase **v3; // rdi

  i_array_p = this->i_array_p;
  v3 = &i_array_p[this->i_count];
  for ( this->i_count = 0; i_array_p < v3; ++i_array_p )
  {
    if ( *i_array_p )
      (*i_array_p)->vfptr->__vecDelDtor(*i_array_p, 1u);
  }
  AMemory::c_free_func(this->i_array_p);
}

