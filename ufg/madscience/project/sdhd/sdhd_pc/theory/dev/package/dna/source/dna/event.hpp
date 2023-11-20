// File Line: 84
// RVA: 0x1A2F20
void __fastcall DNA::Event<void (DNA::PropertyBag *)>::Invoke(DNA::Event<void __cdecl(DNA::PropertyBag *)> *this, DNA::PropertyBag *p1)
{
  unsigned int v2; // ebx
  DNA::PropertyBag *v3; // rsi
  DNA::Event<void __cdecl(DNA::PropertyBag *)> *v4; // rdi
  signed __int64 v5; // rax

  v2 = 0;
  v3 = p1;
  v4 = this;
  if ( this->mDelegates.size )
  {
    do
    {
      v5 = (signed __int64)&v4->mDelegates.p[v2];
      (*(void (__fastcall **)(_QWORD, DNA::PropertyBag *))(v5 + 8))(*(_QWORD *)v5, v3);
      ++v2;
    }
    while ( v2 < v4->mDelegates.size );
  }
}

