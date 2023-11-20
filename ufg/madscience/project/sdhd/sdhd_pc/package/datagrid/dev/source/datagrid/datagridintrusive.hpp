// File Line: 56
// RVA: 0x582B40
void __fastcall UFG::GridIntrusive<UFG::InterestPoint>::Init(UFG::GridIntrusive<UFG::InterestPoint> *this, float x_min, float y_min, float x_max, float y_max, float grid_size)
{
  UFG::GridIntrusive<UFG::InterestPoint> *v6; // rdi
  UFG::qList<UFG::InterestPoint,UFG::InterestPoint,1,0> *v7; // rcx
  UFG::qNode<UFG::InterestPoint,UFG::InterestPoint> **v8; // rbx
  int v9; // ecx
  int v10; // eax
  unsigned __int64 v11; // rsi
  signed __int64 v12; // rax
  unsigned __int8 v13; // cf
  unsigned __int64 v14; // rax
  UFG::allocator::free_link *v15; // rax
  signed __int64 v16; // rbx

  v6 = this;
  v7 = this->mGridNodes;
  if ( v7 )
  {
    v8 = &v7[-1].mNode.mNext;
    `eh vector destructor iterator'(
      v7,
      0x10ui64,
      (int)v7[-1].mNode.mNext,
      (void (__fastcall *)(void *))UFG::qList<UFG::InterestPoint,UFG::InterestPoint,1,0>::~qList<UFG::InterestPoint,UFG::InterestPoint,1,0>);
    operator delete[](v8);
    v6->mGridNodes = 0i64;
  }
  v6->mGridSizeInv = 1.0 / grid_size;
  v6->mGridSize = grid_size;
  v9 = (signed int)(float)((float)(x_max - x_min) * (float)(1.0 / grid_size)) + 1;
  v6->mXDim = v9;
  v10 = (signed int)(float)((float)(y_max - y_min) * (float)(1.0 / grid_size)) + 1;
  v6->mYDim = v10;
  v6->mXMax = x_max;
  v6->mXMin = x_min;
  v6->mYMax = y_max;
  v6->mYMin = y_min;
  v6->mNodeCount = 0;
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
    v16 = (signed __int64)&v15[1];
    `eh vector constructor iterator'(
      &v15[1],
      0x10ui64,
      v11,
      (void (__fastcall *)(void *))UFG::TargetSphere::TargetSphere);
    v6->mGridNodes = (UFG::qList<UFG::InterestPoint,UFG::InterestPoint,1,0> *)v16;
  }
  else
  {
    v6->mGridNodes = 0i64;
  }
}

