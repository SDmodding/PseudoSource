// File Line: 67
// RVA: 0x106860
void __fastcall AListNode<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars>::~AListNode<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars>(
        AListNode<SSInvokedBase,SSInvokedBase> *this)
{
  AListNode<SSInvokedBase,SSInvokedBase> *i_next_p; // rdx
  AListNode<SSInvokedBase,SSInvokedBase> *i_prev_p; // rax

  i_next_p = this->i_next_p;
  if ( this->i_next_p != this )
  {
    i_prev_p = this->i_prev_p;
    i_next_p->i_prev_p = i_prev_p;
    i_prev_p->i_next_p = i_next_p;
    this->i_prev_p = this;
    this->i_next_p = this;
  }
}

// File Line: 319
// RVA: 0xBD380
void __fastcall AList<SSInvokedBase,SSInvokedBase>::~AList<SSInvokedBase,SSInvokedBase>(
        AList<SSInvokedBase,SSInvokedBase> *this)
{
  AList<SSInvokedBase,SSInvokedBase> *i_next_p; // rax
  AList<SSInvokedBase,SSInvokedBase> *v2; // rdx
  AListNode<SSInvokedBase,SSInvokedBase> *v3; // rdx
  AListNode<SSInvokedBase,SSInvokedBase> *i_prev_p; // rax

  i_next_p = (AList<SSInvokedBase,SSInvokedBase> *)this->i_sentinel.i_next_p;
  if ( (AList<SSInvokedBase,SSInvokedBase> *)this->i_sentinel.i_next_p != this )
  {
    do
    {
      v2 = i_next_p;
      i_next_p = (AList<SSInvokedBase,SSInvokedBase> *)i_next_p->i_sentinel.i_next_p;
      v2->i_sentinel.i_next_p = &v2->i_sentinel;
      v2->i_sentinel.i_prev_p = &v2->i_sentinel;
    }
    while ( i_next_p != this );
    this->i_sentinel.i_next_p = &this->i_sentinel;
    this->i_sentinel.i_prev_p = &this->i_sentinel;
  }
  v3 = this->i_sentinel.i_next_p;
  if ( (AList<SSInvokedBase,SSInvokedBase> *)this->i_sentinel.i_next_p != this )
  {
    i_prev_p = this->i_sentinel.i_prev_p;
    v3->i_prev_p = i_prev_p;
    i_prev_p->i_next_p = v3;
    this->i_sentinel.i_prev_p = &this->i_sentinel;
    this->i_sentinel.i_next_p = &this->i_sentinel;
  }
}

// File Line: 571
// RVA: 0x115B50
void __fastcall AList<SSTypeContext::CapturedVars,SSTypeContext::CapturedVars>::free_all(
        AList<SSTypeContext::CapturedVars,SSTypeContext::CapturedVars> *this)
{
  AList<SSTypeContext::CapturedVars,SSTypeContext::CapturedVars> *i_next_p; // rdi
  AList<SSTypeContext::CapturedVars,SSTypeContext::CapturedVars> *v3; // rbx
  AListNode<SSTypeContext::CapturedVars,SSTypeContext::CapturedVars> *v4; // rcx
  AListNode<SSTypeContext::CapturedVars,SSTypeContext::CapturedVars> *i_prev_p; // rax

  i_next_p = (AList<SSTypeContext::CapturedVars,SSTypeContext::CapturedVars> *)this->i_sentinel.i_next_p;
  if ( (AList<SSTypeContext::CapturedVars,SSTypeContext::CapturedVars> *)this->i_sentinel.i_next_p != this )
  {
    do
    {
      v3 = i_next_p;
      i_next_p = (AList<SSTypeContext::CapturedVars,SSTypeContext::CapturedVars> *)i_next_p->i_sentinel.i_next_p;
      this->i_sentinel.i_next_p = &i_next_p->i_sentinel;
      v3->i_sentinel.i_next_p = &v3->i_sentinel;
      AMemory::c_free_func(v3[1].i_sentinel.i_prev_p);
      v4 = v3->i_sentinel.i_next_p;
      if ( (AList<SSTypeContext::CapturedVars,SSTypeContext::CapturedVars> *)v3->i_sentinel.i_next_p != v3 )
      {
        i_prev_p = v3->i_sentinel.i_prev_p;
        v4->i_prev_p = i_prev_p;
        i_prev_p->i_next_p = v4;
        v3->i_sentinel.i_prev_p = &v3->i_sentinel;
        v3->i_sentinel.i_next_p = &v3->i_sentinel;
      }
      operator delete[](v3);
    }
    while ( i_next_p != this );
    this->i_sentinel.i_prev_p = &this->i_sentinel;
  }
}

// File Line: 627
// RVA: 0x1162E0
void __fastcall AList<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars>::free_last(
        AList<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars> *this)
{
  AListNode<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars> *i_prev_p; // rdi
  AListNode<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars> *i_next_p; // rcx
  AListNode<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars> *v3; // rax

  i_prev_p = this->i_sentinel.i_prev_p;
  if ( i_prev_p )
  {
    APSizedArrayBase<SSTypedName>::free_all((APSizedArrayBase<SSTypedName> *)&i_prev_p[1]);
    AMemory::c_free_func(i_prev_p[1].i_prev_p);
    i_next_p = i_prev_p->i_next_p;
    if ( i_prev_p->i_next_p != i_prev_p )
    {
      v3 = i_prev_p->i_prev_p;
      i_next_p->i_prev_p = v3;
      v3->i_next_p = i_next_p;
      i_prev_p->i_prev_p = i_prev_p;
      i_prev_p->i_next_p = i_prev_p;
    }
    operator delete[](i_prev_p);
  }
}

