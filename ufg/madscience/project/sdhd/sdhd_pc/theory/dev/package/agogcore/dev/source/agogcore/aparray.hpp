// File Line: 298
// RVA: 0x223720
void __fastcall APArray<ASymbol,ASymbol,ACompareLogical<ASymbol>>::~APArray<ASymbol,ASymbol,ACompareLogical<ASymbol>>(AVCompactSorted<ASymbol,ASymbol,ACompareLogical<ASymbol> > *this)
{
  AMemory::c_free_func(this->i_array_p);
}

// File Line: 320
// RVA: 0x107A00
APArray<SSInstance,SSInstance,ACompareAddress<SSInstance> > *__fastcall APArray<SSInstance,SSInstance,ACompareAddress<SSInstance>>::operator=(APArray<SSInstance,SSInstance,ACompareAddress<SSInstance> > *this, APArrayBase<SSInstance> *array)
{
  __int64 v2; // rdi
  APArrayBase<SSInstance> *v3; // rsi
  APArray<SSInstance,SSInstance,ACompareAddress<SSInstance> > *v4; // rbx
  unsigned int v5; // eax
  SSInstance **v6; // rcx

  v2 = array->i_count;
  v3 = array;
  v4 = this;
  if ( (unsigned int)v2 > this->i_size )
  {
    AMemory::c_free_func(this->i_array_p);
    v5 = AMemory::c_req_byte_size_func(8 * v2) >> 3;
    v4->i_size = v5;
    v4->i_array_p = APArrayBase<SSInstance>::alloc_array(v5);
  }
  v6 = v4->i_array_p;
  v4->i_count = v2;
  memmove(v6, v3->i_array_p, 8 * v2);
  return v4;
}

// File Line: 358
// RVA: 0x4CC090
APArray<SSActor,SSActor,ACompareAddress<SSActor> > *__fastcall APArray<SSActor,SSActor,ACompareAddress<SSActor>>::operator=(APArray<SSActor,SSActor,ACompareAddress<SSActor> > *this, APArrayBase<SSActor> *array)
{
  __int64 v2; // rdi
  APArrayBase<SSActor> *v3; // rsi
  APArray<SSActor,SSActor,ACompareAddress<SSActor> > *v4; // rbx
  unsigned int v5; // eax
  SSActor **v6; // rcx

  v2 = array->i_count;
  v3 = array;
  v4 = this;
  if ( (unsigned int)v2 > this->i_size )
  {
    AMemory::c_free_func(this->i_array_p);
    v5 = AMemory::c_req_byte_size_func(8 * v2) >> 3;
    v4->i_size = v5;
    v4->i_array_p = APArrayBase<SSActor>::alloc_array(v5);
  }
  v6 = v4->i_array_p;
  v4->i_count = v2;
  memmove(v6, v3->i_array_p, 8 * v2);
  return v4;
}

// File Line: 618
// RVA: 0x10B660
void __fastcall APArray<SSData,ASymbol,ACompareLogical<ASymbol>>::append(APArray<SSData,ASymbol,ACompareLogical<ASymbol> > *this, SSData *elem)
{
  __int64 v2; // rdi
  APArray<SSData,ASymbol,ACompareLogical<ASymbol> > *v3; // rbx
  SSData *v4; // rsi
  SSData **v5; // rbp
  unsigned __int64 v6; // rax
  SSData **v7; // rax

  v2 = this->i_count;
  v3 = this;
  v4 = elem;
  if ( this->i_size < (unsigned int)(v2 + 1) )
  {
    v5 = this->i_array_p;
    if ( (_DWORD)v2 == -1 )
      LODWORD(v6) = 0;
    else
      v6 = (unsigned __int64)AMemory::c_req_byte_size_func(8 * (v2 & 0xFFFFFFFC) + 32) >> 3;
    v3->i_size = v6;
    v7 = APArrayBase<SSData>::alloc_array(v6);
    v3->i_array_p = v7;
    memmove(v7, v5, 8 * v2);
    AMemory::c_free_func(v5);
  }
  v3->i_array_p[v2] = v4;
  ++v3->i_count;
}

// File Line: 688
// RVA: 0x10D200
void __fastcall APArray<SSInstance,SSInstance,ACompareAddress<SSInstance>>::append_all(APArray<SSInstance,SSInstance,ACompareAddress<SSInstance> > *this, APArray<SSInstance,SSInstance,ACompareAddress<SSInstance> > *array, unsigned int pos, unsigned int elem_count)
{
  unsigned int v4; // ebx
  __int64 v5; // rsi
  APArray<SSInstance,SSInstance,ACompareAddress<SSInstance> > *v6; // r14
  APArray<SSInstance,SSInstance,ACompareAddress<SSInstance> > *v7; // rdi

  v4 = elem_count;
  v5 = pos;
  v6 = array;
  v7 = this;
  if ( elem_count == -1 )
    v4 = array->i_count - pos;
  if ( v4 )
  {
    APSizedArrayBase<SSInstance>::ensure_size((APSizedArrayBase<SSInstance> *)&this->i_count, v4 + this->i_count);
    memmove(&v7->i_array_p[v7->i_count], &v6->i_array_p[v5], 8i64 * v4);
    v7->i_count += v4;
  }
}

// File Line: 733
// RVA: 0x10D3C0
void __fastcall APArray<SSInvokedMethod,SSInvokedMethod,ACompareAddress<SSInvokedMethod>>::append_all(APArray<SSInvokedMethod,SSInvokedMethod,ACompareAddress<SSInvokedMethod> > *this, SSInvokedMethod *elems_p, unsigned int elem_count)
{
  SSInvokedMethod *v3; // rbx
  unsigned int v4; // esi
  APArray<SSInvokedMethod,SSInvokedMethod,ACompareAddress<SSInvokedMethod> > *v5; // rdi
  SSInvokedMethod **v6; // r9
  __int64 v7; // rax

  if ( elem_count )
  {
    v3 = elems_p;
    v4 = elem_count;
    v5 = this;
    APSizedArrayBase<SSInvokedMethod>::ensure_size(
      (APSizedArrayBase<SSInvokedMethod> *)&this->i_count,
      elem_count + this->i_count);
    v6 = &v5->i_array_p[v5->i_count];
    if ( v4 )
    {
      v7 = v4;
      do
      {
        *v6 = v3;
        ++v3;
        ++v6;
        --v7;
      }
      while ( v7 );
    }
    v5->i_count += v4;
  }
}

// File Line: 1178
// RVA: 0x131150
void __fastcall APArray<SSInstance,SSInstance,ACompareAddress<SSInstance>>::pop_all(APArray<SSInstance,SSInstance,ACompareAddress<SSInstance> > *this, APArray<SSInstance,SSInstance,ACompareAddress<SSInstance> > *collected_p, unsigned int pos, unsigned int elem_count)
{
  unsigned int v4; // esi
  __int64 v5; // rbp
  APArray<SSInstance,SSInstance,ACompareAddress<SSInstance> > *v6; // r15
  APArray<SSInstance,SSInstance,ACompareAddress<SSInstance> > *v7; // r14
  SSInstance **v8; // rcx

  v4 = elem_count;
  v5 = pos;
  v6 = collected_p;
  v7 = this;
  if ( elem_count == -1 )
    v4 = this->i_count - pos;
  if ( v4 )
  {
    APSizedArrayBase<SSInstance>::ensure_size(
      (APSizedArrayBase<SSInstance> *)&collected_p->i_count,
      v4 + collected_p->i_count);
    memmove(&v6->i_array_p[v6->i_count], &v7->i_array_p[v5], 8i64 * v4);
    v6->i_count += v4;
    v8 = v7->i_array_p;
    v7->i_count -= v4;
    memmove(&v8[v5], &v8[v4 + v5], 8i64 * (unsigned int)(v7->i_count - v5));
  }
}

// File Line: 1587
// RVA: 0x13C260
void __fastcall APArray<SSInstance,SSInstance,ACompareAddress<SSInstance>>::set_all(APArray<SSInstance,SSInstance,ACompareAddress<SSInstance> > *this, SSInstance *elem_p, unsigned int pos, unsigned int elem_count)
{
  unsigned int v4; // ebx
  __int64 v5; // r14
  SSInstance *v6; // rdi
  APArray<SSInstance,SSInstance,ACompareAddress<SSInstance> > *v7; // rsi
  unsigned int v8; // ebp
  SSInstance **v9; // rax

  v4 = elem_count;
  v5 = pos;
  v6 = elem_p;
  v7 = this;
  if ( elem_count == -1 )
    v4 = this->i_count - pos;
  if ( v4 )
  {
    v8 = pos + v4;
    APSizedArrayBase<SSInstance>::ensure_size((APSizedArrayBase<SSInstance> *)&this->i_count, pos + v4);
    v9 = v7->i_array_p;
    if ( v7->i_count < v8 )
      v7->i_count = v8;
    do
    {
      v9[v5] = v6;
      --v4;
    }
    while ( v4 );
  }
}

// File Line: 2381
// RVA: 0x106880
void __fastcall APArrayFree<SSInvokeBase,SSInvokeBase,ACompareAddress<SSInvokeBase>>::~APArrayFree<SSInvokeBase,SSInvokeBase,ACompareAddress<SSInvokeBase>>(APArrayFree<SSInvokeBase,SSInvokeBase,ACompareAddress<SSInvokeBase> > *this)
{
  APArrayFree<SSInvokeBase,SSInvokeBase,ACompareAddress<SSInvokeBase> > *v1; // rsi
  SSInvokeBase **v2; // rbx
  unsigned __int64 v3; // rdi

  v1 = this;
  v2 = this->i_array_p;
  v3 = (unsigned __int64)&v2[this->i_count];
  for ( this->i_count = 0; (unsigned __int64)v2 < v3; ++v2 )
  {
    if ( *v2 )
      (*v2)->vfptr->__vecDelDtor(*v2, 1u);
  }
  AMemory::c_free_func(v1->i_array_p);
}

