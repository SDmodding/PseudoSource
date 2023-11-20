// File Line: 732
// RVA: 0x4A1810
void __fastcall qSetBase<UFG::ProgressionTracker::LayerOwnershipInfo>::FreeAll(qSetBase<UFG::ProgressionTracker::LayerOwnershipInfo> *this)
{
  void **v1; // rbx
  qSetBase<UFG::ProgressionTracker::LayerOwnershipInfo> *v2; // rsi
  unsigned __int64 v3; // rdi

  v1 = (void **)this->mppArray;
  v2 = this;
  v3 = (unsigned __int64)&v1[this->mCount];
  if ( (unsigned __int64)v1 >= v3 )
  {
    this->mCount = 0;
  }
  else
  {
    do
    {
      if ( *v1 )
        operator delete[](*v1);
      ++v1;
    }
    while ( (unsigned __int64)v1 < v3 );
    v2->mCount = 0;
  }
}

