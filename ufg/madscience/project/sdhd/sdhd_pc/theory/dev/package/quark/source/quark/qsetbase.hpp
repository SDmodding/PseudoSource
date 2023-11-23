// File Line: 732
// RVA: 0x4A1810
void __fastcall qSetBase<UFG::ProgressionTracker::LayerOwnershipInfo>::FreeAll(
        qSetBase<UFG::ProgressionTracker::LayerOwnershipInfo> *this)
{
  void **mppArray; // rbx
  void **v3; // rdi

  mppArray = (void **)this->mppArray;
  v3 = &mppArray[this->mCount];
  if ( mppArray >= v3 )
  {
    this->mCount = 0;
  }
  else
  {
    do
    {
      if ( *mppArray )
        operator delete[](*mppArray);
      ++mppArray;
    }
    while ( mppArray < v3 );
    this->mCount = 0;
  }
}

