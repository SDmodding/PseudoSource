// File Line: 84
// RVA: 0x1A2F20
void __fastcall DNA::Event<void (DNA::PropertyBag *)>::Invoke(
        DNA::Event<void __cdecl(DNA::PropertyBag *)> *this,
        DNA::PropertyBag *p1)
{
  unsigned int i; // ebx
  fastdelegate::FastDelegate1<DNA::PropertyBag *,void> *v5; // rax

  for ( i = 0; i < this->mDelegates.size; ++i )
  {
    v5 = &this->mDelegates.p[i];
    ((void (__fastcall *)(fastdelegate::detail::GenericClass *, DNA::PropertyBag *))v5->m_Closure.m_pFunction)(
      v5->m_Closure.m_pthis,
      p1);
  }
}

