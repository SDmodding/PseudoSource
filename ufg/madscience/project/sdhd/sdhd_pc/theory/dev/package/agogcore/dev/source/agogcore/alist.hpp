// File Line: 67
// RVA: 0x106860
void __fastcall AListNode<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars>::~AListNode<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars>(AListNode<SSInvokedBase,SSInvokedBase> *this)
{
  AListNode<SSInvokedBase,SSInvokedBase> *v1; // rdx
  AListNode<SSInvokedBase,SSInvokedBase> *v2; // rax

  v1 = this->i_next_p;
  if ( this->i_next_p != this )
  {
    v2 = this->i_prev_p;
    v1->i_prev_p = v2;
    v2->i_next_p = v1;
    this->i_prev_p = this;
    this->i_next_p = this;
  }
}

// File Line: 319
// RVA: 0xBD380
void __fastcall AList<SSInvokedBase,SSInvokedBase>::~AList<SSInvokedBase,SSInvokedBase>(AList<SSInvokedBase,SSInvokedBase> *this)
{
  AList<SSInvokedBase,SSInvokedBase> *v1; // rax
  AList<SSInvokedBase,SSInvokedBase> *v2; // rdx
  AListNode<SSInvokedBase,SSInvokedBase> *v3; // rdx
  AListNode<SSInvokedBase,SSInvokedBase> *v4; // rax

  v1 = (AList<SSInvokedBase,SSInvokedBase> *)this->i_sentinel.i_next_p;
  if ( (AList<SSInvokedBase,SSInvokedBase> *)this->i_sentinel.i_next_p != this )
  {
    do
    {
      v2 = v1;
      v1 = (AList<SSInvokedBase,SSInvokedBase> *)v1->i_sentinel.i_next_p;
      v2->i_sentinel.i_next_p = &v2->i_sentinel;
      v2->i_sentinel.i_prev_p = &v2->i_sentinel;
    }
    while ( v1 != this );
    this->i_sentinel.i_next_p = &this->i_sentinel;
    this->i_sentinel.i_prev_p = &this->i_sentinel;
  }
  v3 = this->i_sentinel.i_next_p;
  if ( (AList<SSInvokedBase,SSInvokedBase> *)this->i_sentinel.i_next_p != this )
  {
    v4 = this->i_sentinel.i_prev_p;
    v3->i_prev_p = v4;
    v4->i_next_p = v3;
    this->i_sentinel.i_prev_p = &this->i_sentinel;
    this->i_sentinel.i_next_p = &this->i_sentinel;
  }
}

// File Line: 571
// RVA: 0x115B50
void __fastcall AList<SSTypeContext::CapturedVars,SSTypeContext::CapturedVars>::free_all(AList<SSTypeContext::CapturedVars,SSTypeContext::CapturedVars> *this)
{
  AList<SSTypeContext::CapturedVars,SSTypeContext::CapturedVars> *v1; // rsi
  AListNode<SSTypeContext::CapturedVars,SSTypeContext::CapturedVars> *v2; // rdi
  AListNode<SSTypeContext::CapturedVars,SSTypeContext::CapturedVars> *v3; // rbx
  AListNode<SSTypeContext::CapturedVars,SSTypeContext::CapturedVars> *v4; // rcx
  AListNode<SSTypeContext::CapturedVars,SSTypeContext::CapturedVars> *v5; // rax

  v1 = this;
  v2 = this->i_sentinel.i_next_p;
  if ( (AList<SSTypeContext::CapturedVars,SSTypeContext::CapturedVars> *)this->i_sentinel.i_next_p != this )
  {
    do
    {
      v3 = v2;
      v2 = v2->i_next_p;
      v1->i_sentinel.i_next_p = v2;
      v3->i_next_p = v3;
      AMemory::c_free_func(v3[1].i_prev_p);
      v4 = v3->i_next_p;
      if ( v3->i_next_p != v3 )
      {
        v5 = v3->i_prev_p;
        v4->i_prev_p = v5;
        v5->i_next_p = v4;
        v3->i_prev_p = v3;
        v3->i_next_p = v3;
      }
      operator delete[](v3);
    }
    while ( v2 != (AListNode<SSTypeContext::CapturedVars,SSTypeContext::CapturedVars> *)v1 );
    v1->i_sentinel.i_prev_p = &v1->i_sentinel;
  }
}

// File Line: 627
// RVA: 0x1162E0
void __fastcall AList<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars>::free_last(AList<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars> *this)
{
  AListNode<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars> *v1; // rdi
  AListNode<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars> *v2; // rcx
  AListNode<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars> *v3; // rax

  v1 = this->i_sentinel.i_prev_p;
  if ( v1 )
  {
    APSizedArrayBase<SSTypedName>::free_all((APSizedArrayBase<SSTypedName> *)&v1[1]);
    AMemory::c_free_func(v1[1].i_prev_p);
    v2 = v1->i_next_p;
    if ( v1->i_next_p != v1 )
    {
      v3 = v1->i_prev_p;
      v2->i_prev_p = v3;
      v3->i_next_p = v2;
      v1->i_prev_p = v1;
      v1->i_next_p = v1;
    }
    operator delete[](v1);
  }
}

