// File Line: 37
// RVA: 0xE2520
void __fastcall UFG::WayGraph::~WayGraph(UFG::WayGraph *this)
{
  this->vfptr = (UFG::WayGraphVtbl *)&UFG::WayGraph::`vftable;
}

// File Line: 68
// RVA: 0xE2A50
float __fastcall Scaleform::GFx::DisplayObjectBase::GetRatio(hkDataArrayImpl *this, int index)
{
  return 0.0;
}

// File Line: 78
// RVA: 0xBD960
void __fastcall UFG::WayFinderClient::~WayFinderClient(UFG::WayFinderClient *this)
{
  this->vfptr = (UFG::WayFinderClientVtbl *)&UFG::WayFinderClient::`vftable;
}

// File Line: 96
// RVA: 0xC49A0
UFG::qVector3 *__fastcall UFG::WayFinderClient::GetPosition(UFG::WayFinderClient *this, UFG::qVector3 *result)
{
  *result = this->m_CurrPos;
  return result;
}

// File Line: 97
// RVA: 0xC0F20
UFG::qVector3 *__fastcall UFG::WayFinderClient::GetDirection(UFG::WayFinderClient *this, UFG::qVector3 *result)
{
  *result = this->m_CurrDir;
  return result;
}

// File Line: 190
// RVA: 0xE2610
char *__fastcall UFG::WayStarNode::operator new(unsigned __int64 size)
{
  char *mFreeListHead; // rbx

  mFreeListHead = UFG::WayFinder::s_NodePool.mFreeListHead;
  if ( UFG::WayFinder::s_NodePool.mFreeListHead )
  {
    UFG::WayFinder::s_NodePool.mFreeListHead = *(char **)UFG::WayFinder::s_NodePool.mFreeListHead;
    if ( UFG::WayFinder::s_NodePool.mMostSlotsAllocated <= ++UFG::WayFinder::s_NodePool.mNumSlotsAllocated )
    {
      UFG::WayFinder::s_NodePool.mMostSlotsAllocated = UFG::WayFinder::s_NodePool.mNumSlotsAllocated;
      return mFreeListHead;
    }
  }
  else
  {
    UFG::qFixedAllocator::ReportFull(&UFG::WayFinder::s_NodePool);
  }
  return mFreeListHead;
}

// File Line: 191
// RVA: 0xE26D0
void __fastcall UFG::WayStarNode::operator delete(char *ptr)
{
  *(_QWORD *)ptr = UFG::WayFinder::s_NodePool.mFreeListHead;
  --UFG::WayFinder::s_NodePool.mNumSlotsAllocated;
  UFG::WayFinder::s_NodePool.mFreeListHead = ptr;
}

// File Line: 228
// RVA: 0xE2670
char *__fastcall UFG::WayStarSearch::operator new(unsigned __int64 size)
{
  char *mFreeListHead; // rbx

  mFreeListHead = UFG::WayFinder::s_SearchPool.mFreeListHead;
  if ( UFG::WayFinder::s_SearchPool.mFreeListHead )
  {
    UFG::WayFinder::s_SearchPool.mFreeListHead = *(char **)UFG::WayFinder::s_SearchPool.mFreeListHead;
    if ( UFG::WayFinder::s_SearchPool.mMostSlotsAllocated <= ++UFG::WayFinder::s_SearchPool.mNumSlotsAllocated )
    {
      UFG::WayFinder::s_SearchPool.mMostSlotsAllocated = UFG::WayFinder::s_SearchPool.mNumSlotsAllocated;
      return mFreeListHead;
    }
  }
  else
  {
    UFG::qFixedAllocator::ReportFull(&UFG::WayFinder::s_SearchPool);
  }
  return mFreeListHead;
}

// File Line: 229
// RVA: 0xE26F0
void __fastcall UFG::WayStarSearch::operator delete(char *ptr)
{
  *(_QWORD *)ptr = UFG::WayFinder::s_SearchPool.mFreeListHead;
  --UFG::WayFinder::s_SearchPool.mNumSlotsAllocated;
  UFG::WayFinder::s_SearchPool.mFreeListHead = ptr;
}

