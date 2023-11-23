// File Line: 312
// RVA: 0x490140
void __fastcall qSet<UFG::qSafePointer<UFG::SimObject,UFG::SimObject>,UFG::qSafePointer<UFG::SimObject,UFG::SimObject>,qCompareAddress<UFG::qSafePointer<UFG::SimObject,UFG::SimObject>>>::~qSet<UFG::qSafePointer<UFG::SimObject,UFG::SimObject>,UFG::qSafePointer<UFG::SimObject,UFG::SimObject>,qCompareAddress<UFG::qSafePointer<UFG::SimObject,UFG::SimObject>>>(
        qSet<UFG::SceneObjectProperties,UFG::qSymbol,qCompareLogical<UFG::qSymbol> > *this)
{
  operator delete[](this->mppArray);
}

// File Line: 455
// RVA: 0x239E50
void __fastcall qSet<UFG::SceneObjectProperties,UFG::qSymbol,qCompareLogical<UFG::qSymbol>>::Append(
        qSet<UFG::SceneObjectProperties,UFG::qSymbol,qCompareLogical<UFG::qSymbol> > *this,
        UFG::SceneObjectProperties *elem,
        const char *reason)
{
  __int64 mCount; // rdi
  unsigned int mBufferSize; // eax
  UFG::SceneObjectProperties **mppArray; // rbp
  unsigned __int64 v8; // rax
  unsigned __int64 v9; // kr00_8
  UFG::SceneObjectProperties **v10; // rax

  mCount = this->mCount;
  mBufferSize = this->mBufferSize;
  if ( mBufferSize < (int)mCount + 1 )
  {
    mppArray = this->mppArray;
    if ( mBufferSize )
    {
      do
        mBufferSize *= 2;
      while ( mBufferSize < (int)mCount + 1 );
    }
    else
    {
      mBufferSize = mCount + 1;
    }
    this->mBufferSize = mBufferSize;
    v9 = mBufferSize;
    v8 = 8i64 * mBufferSize;
    if ( !is_mul_ok(v9, 8ui64) )
      v8 = -1i64;
    v10 = (UFG::SceneObjectProperties **)UFG::qMalloc(v8, reason, 0i64);
    this->mppArray = v10;
    UFG::qMemCopy(v10, mppArray, 8 * mCount);
    operator delete[](mppArray);
  }
  this->mppArray[mCount] = elem;
  ++this->mCount;
}

