// File Line: 56
// RVA: 0x582B40
void __fastcall UFG::GridIntrusive<UFG::InterestPoint>::Init(
        UFG::GridIntrusive<UFG::InterestPoint> *this,
        float x_min,
        float y_min,
        float x_max,
        float y_max,
        float grid_size)
{
  UFG::qList<UFG::InterestPoint,UFG::InterestPoint,1,0> *mGridNodes; // rcx
  UFG::qNode<UFG::InterestPoint,UFG::InterestPoint> **p_mNext; // rbx
  int v9; // ecx
  int v10; // eax
  unsigned __int64 v11; // rsi
  __int64 v12; // rax
  bool v13; // cf
  unsigned __int64 v14; // rax
  UFG::allocator::free_link *v15; // rax
  UFG::qList<UFG::InterestPoint,UFG::InterestPoint,1,0> *v16; // rbx

  mGridNodes = this->mGridNodes;
  if ( mGridNodes )
  {
    p_mNext = &mGridNodes[-1].mNode.mNext;
    `eh vector destructor iterator(
      mGridNodes,
      0x10ui64,
      (int)mGridNodes[-1].mNode.mNext,
      (void (__fastcall *)(void *))UFG::qList<UFG::InterestPoint,UFG::InterestPoint,1,0>::~qList<UFG::InterestPoint,UFG::InterestPoint,1,0>);
    operator delete[](p_mNext);
    this->mGridNodes = 0i64;
  }
  this->mGridSizeInv = 1.0 / grid_size;
  this->mGridSize = grid_size;
  v9 = (int)(float)((float)(x_max - x_min) * (float)(1.0 / grid_size)) + 1;
  this->mXDim = v9;
  v10 = (int)(float)((float)(y_max - y_min) * (float)(1.0 / grid_size)) + 1;
  this->mYDim = v10;
  this->mXMax = x_max;
  this->mXMin = x_min;
  this->mYMax = y_max;
  this->mYMin = y_min;
  this->mNodeCount = 0;
  v11 = v9 * v10;
  v12 = 16 * v11;
  if ( !is_mul_ok(v11, 0x10ui64) )
    v12 = -1i64;
  v13 = __CFADD__(v12, 8i64);
  v14 = v12 + 8;
  if ( v13 )
    v14 = -1i64;
  v15 = UFG::qMalloc(v14, "GridNodes", 0i64);
  if ( v15 )
  {
    LODWORD(v15->mNext) = v11;
    v16 = (UFG::qList<UFG::InterestPoint,UFG::InterestPoint,1,0> *)&v15[1];
    `eh vector constructor iterator(
      &v15[1],
      0x10ui64,
      v11,
      (void (__fastcall *)(void *))UFG::TargetSphere::TargetSphere);
    this->mGridNodes = v16;
  }
  else
  {
    this->mGridNodes = 0i64;
  }
}

