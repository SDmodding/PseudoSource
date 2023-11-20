// File Line: 312
// RVA: 0x490140
void __fastcall qSet<UFG::qSafePointer<UFG::SimObject,UFG::SimObject>,UFG::qSafePointer<UFG::SimObject,UFG::SimObject>,qCompareAddress<UFG::qSafePointer<UFG::SimObject,UFG::SimObject>>>::~qSet<UFG::qSafePointer<UFG::SimObject,UFG::SimObject>,UFG::qSafePointer<UFG::SimObject,UFG::SimObject>,qCompareAddress<UFG::qSafePointer<UFG::SimObject,UFG::SimObject>>>(qSet<UFG::SceneObjectProperties,UFG::qSymbol,qCompareLogical<UFG::qSymbol> > *this)
{
  operator delete[](this->mppArray);
}

// File Line: 455
// RVA: 0x239E50
void __fastcall qSet<UFG::SceneObjectProperties,UFG::qSymbol,qCompareLogical<UFG::qSymbol>>::Append(qSet<UFG::SceneObjectProperties,UFG::qSymbol,qCompareLogical<UFG::qSymbol> > *this, UFG::SceneObjectProperties *elem, const char *reason)
{
  __int64 v3; // rdi
  qSet<UFG::SceneObjectProperties,UFG::qSymbol,qCompareLogical<UFG::qSymbol> > *v4; // rbx
  unsigned int v5; // eax
  UFG::SceneObjectProperties *v6; // rsi
  UFG::SceneObjectProperties **v7; // rbp
  unsigned __int64 v8; // rax
  unsigned __int64 v9; // kr00_8
  UFG::allocator::free_link *v10; // rax

  v3 = this->mCount;
  v4 = this;
  v5 = this->mBufferSize;
  v6 = elem;
  if ( v5 < (signed int)v3 + 1 )
  {
    v7 = this->mppArray;
    if ( v5 )
    {
      do
        v5 *= 2;
      while ( v5 < (signed int)v3 + 1 );
    }
    else
    {
      v5 = v3 + 1;
    }
    this->mBufferSize = v5;
    v9 = v5;
    v8 = 8i64 * v5;
    if ( !is_mul_ok(v9, 8ui64) )
      v8 = -1i64;
    v10 = UFG::qMalloc(v8, reason, 0i64);
    v4->mppArray = (UFG::SceneObjectProperties **)v10;
    UFG::qMemCopy(v10, v7, 8 * v3);
    operator delete[](v7);
  }
  v4->mppArray[v3] = v6;
  ++v4->mCount;
}

