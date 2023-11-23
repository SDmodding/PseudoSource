// File Line: 51
// RVA: 0xDC7C0
void __fastcall UFG::Grid<UFG::RoadNetworkSegment>::Init(
        UFG::Grid<UFG::RoadNetworkSegment> *this,
        float x_min,
        float y_min,
        float x_max,
        float y_max,
        float grid_size)
{
  UFG::qList<UFG::qPointerNode<UFG::RoadNetworkSegment>,UFG::qPointerNode<UFG::RoadNetworkSegment>,1,0> *mGridNodes; // rcx
  UFG::qNode<UFG::qPointerNode<UFG::RoadNetworkSegment>,UFG::qPointerNode<UFG::RoadNetworkSegment> > **p_mNext; // rbx
  int v9; // ecx
  int v10; // eax
  unsigned __int64 v11; // rsi
  __int64 v12; // rax
  bool v13; // cf
  unsigned __int64 v14; // rax
  char *v15; // rax
  UFG::qList<UFG::qPointerNode<UFG::RoadNetworkSegment>,UFG::qPointerNode<UFG::RoadNetworkSegment>,1,0> *v16; // rbx

  mGridNodes = this->mGridNodes;
  if ( mGridNodes )
  {
    p_mNext = &mGridNodes[-1].mNode.mNext;
    `eh vector destructor iterator(
      mGridNodes,
      0x10ui64,
      (int)mGridNodes[-1].mNode.mNext,
      (void (__fastcall *)(void *))UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0>::~qList<UFG::qReflectField,UFG::qReflectField,1,0>);
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
    *(_DWORD *)v15 = v11;
    v16 = (UFG::qList<UFG::qPointerNode<UFG::RoadNetworkSegment>,UFG::qPointerNode<UFG::RoadNetworkSegment>,1,0> *)(v15 + 8);
    `eh vector constructor iterator(
      v15 + 8,
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

// File Line: 147
// RVA: 0xD13A0
__int64 __fastcall UFG::Grid<UFG::RoadNetworkSegment>::Add(
        UFG::Grid<UFG::RoadNetworkSegment> *this,
        UFG::RoadNetworkSegment *data,
        unsigned int bucket_index)
{
  UFG::qList<UFG::qPointerNode<UFG::RoadNetworkSegment>,UFG::qPointerNode<UFG::RoadNetworkSegment>,1,0> *v6; // rbx
  UFG::qNode<UFG::qPointerNode<UFG::RoadNetworkSegment>,UFG::qPointerNode<UFG::RoadNetworkSegment> > *mPrev; // rax
  char *v8; // rax
  char *v9; // rcx
  UFG::qNode<UFG::qPointerNode<UFG::RoadNetworkSegment>,UFG::qPointerNode<UFG::RoadNetworkSegment> > *v10; // rax

  v6 = &this->mGridNodes[bucket_index];
  mPrev = v6->mNode.mPrev;
  if ( (UFG::qList<UFG::qPointerNode<UFG::RoadNetworkSegment>,UFG::qPointerNode<UFG::RoadNetworkSegment>,1,0> *)v6->mNode.mPrev == v6 )
  {
LABEL_4:
    v8 = UFG::qMalloc(0x18ui64, "grid pointer node", 0i64);
    v9 = v8;
    if ( v8 )
    {
      *(_QWORD *)v8 = v8;
      *((_QWORD *)v8 + 1) = v8;
      *((_QWORD *)v8 + 2) = data;
    }
    else
    {
      v9 = 0i64;
    }
    v10 = v6->mNode.mPrev;
    v10->mNext = (UFG::qNode<UFG::qPointerNode<UFG::RoadNetworkSegment>,UFG::qPointerNode<UFG::RoadNetworkSegment> > *)v9;
    *(_QWORD *)v9 = v10;
    *((_QWORD *)v9 + 1) = v6;
    v6->mNode.mPrev = (UFG::qNode<UFG::qPointerNode<UFG::RoadNetworkSegment>,UFG::qPointerNode<UFG::RoadNetworkSegment> > *)v9;
    ++this->mNodeCount;
  }
  else
  {
    while ( (UFG::RoadNetworkSegment *)mPrev[1].mPrev != data )
    {
      mPrev = mPrev->mPrev;
      if ( mPrev == (UFG::qNode<UFG::qPointerNode<UFG::RoadNetworkSegment>,UFG::qPointerNode<UFG::RoadNetworkSegment> > *)v6 )
        goto LABEL_4;
    }
  }
  return bucket_index;
}

// File Line: 406
// RVA: 0xCF660
void __fastcall UFG::GridNodesArray<UFG::RoadNetworkSegment>::GridNodesArray<UFG::RoadNetworkSegment>(
        UFG::GridNodesArray<UFG::RoadNetworkSegment> *this,
        UFG::Grid<UFG::RoadNetworkSegment> *grid,
        float x,
        float y)
{
  float mXMin; // xmm4_4
  char v5; // r15
  float mYMin; // xmm1_4
  int v8; // r12d
  float v9; // xmm3_4
  float v10; // xmm2_4
  int v11; // r8d
  UFG::qList<UFG::qPointerNode<UFG::RoadNetworkSegment>,UFG::qPointerNode<UFG::RoadNetworkSegment>,1,0> *v12; // rdx
  int v13; // r9d
  int v14; // esi
  int v15; // ebp
  int v16; // edi
  __int64 v17; // r14
  __int64 v18; // r11
  int i; // edx
  int mXDim; // eax
  UFG::qList<UFG::qPointerNode<UFG::RoadNetworkSegment>,UFG::qPointerNode<UFG::RoadNetworkSegment>,1,0> *v21; // r8

  mXMin = grid->mXMin;
  v5 = 0;
  if ( x <= mXMin )
    x = grid->mXMin;
  if ( x >= grid->mXMax )
    x = grid->mXMax;
  mYMin = grid->mYMin;
  if ( y <= mYMin )
    y = grid->mYMin;
  if ( y >= grid->mYMax )
    y = grid->mYMax;
  v8 = 3;
  v9 = (float)(y - mYMin) * grid->mGridSizeInv;
  v10 = (float)(x - mXMin) * grid->mGridSizeInv;
  this->mNumValidNodes = 0;
  v11 = (int)v9;
  v12 = &grid->mGridNodes[(int)v10 + (int)v9 * grid->mXDim];
  if ( (UFG::qList<UFG::qPointerNode<UFG::RoadNetworkSegment>,UFG::qPointerNode<UFG::RoadNetworkSegment>,1,0> *)v12->mNode.mNext != v12 )
  {
    this->mGridNodeArray[0] = v12;
    ++this->mNumValidNodes;
    v5 = 1;
  }
  while ( 1 )
  {
    v13 = v8 / -2 + (int)v10;
    v14 = v8 / -2 + v11;
    v15 = v13 + v8;
    v16 = v14 + v8;
    if ( v13 < v13 + v8 )
    {
      v17 = v13;
      v18 = v13;
      do
      {
        for ( i = v14; i < v16; ++i )
        {
          if ( (v18 == v17 || v13 == v15 - 1 || i == v14 || i == v16 - 1) && v18 >= 0 )
          {
            mXDim = grid->mXDim;
            if ( v13 < mXDim && i >= 0 && i < grid->mYDim )
            {
              v21 = &grid->mGridNodes[v13 + i * mXDim];
              if ( (UFG::qList<UFG::qPointerNode<UFG::RoadNetworkSegment>,UFG::qPointerNode<UFG::RoadNetworkSegment>,1,0> *)v21->mNode.mNext != v21 )
              {
                v5 = 1;
                this->mGridNodeArray[this->mNumValidNodes++] = v21;
              }
            }
          }
        }
        ++v13;
        ++v18;
      }
      while ( v13 < v15 );
      v11 = (int)v9;
    }
    if ( v5 )
      break;
    v8 += 2;
  }
}

