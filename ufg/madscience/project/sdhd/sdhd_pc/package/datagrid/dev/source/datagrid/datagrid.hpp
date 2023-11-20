// File Line: 51
// RVA: 0xDC7C0
void __fastcall UFG::Grid<UFG::RoadNetworkSegment>::Init(UFG::Grid<UFG::RoadNetworkSegment> *this, float x_min, float y_min, float x_max, float y_max, float grid_size)
{
  UFG::Grid<UFG::RoadNetworkSegment> *v6; // rdi
  UFG::qList<UFG::qPointerNode<UFG::RoadNetworkSegment>,UFG::qPointerNode<UFG::RoadNetworkSegment>,1,0> *v7; // rcx
  UFG::qNode<UFG::qPointerNode<UFG::RoadNetworkSegment>,UFG::qPointerNode<UFG::RoadNetworkSegment> > **v8; // rbx
  int v9; // ecx
  int v10; // eax
  unsigned __int64 v11; // rsi
  signed __int64 v12; // rax
  unsigned __int8 v13; // cf
  unsigned __int64 v14; // rax
  char *v15; // rax
  signed __int64 v16; // rbx

  v6 = this;
  v7 = this->mGridNodes;
  if ( v7 )
  {
    v8 = &v7[-1].mNode.mNext;
    `eh vector destructor iterator(
      v7,
      0x10ui64,
      (int)v7[-1].mNode.mNext,
      (void (__fastcall *)(void *))UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0>::~qList<UFG::qReflectField,UFG::qReflectField,1,0>);
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
    *(_DWORD *)v15 = v11;
    v16 = (signed __int64)(v15 + 8);
    `eh vector constructor iterator(
      v15 + 8,
      0x10ui64,
      v11,
      (void (__fastcall *)(void *))UFG::TargetSphere::TargetSphere);
    v6->mGridNodes = (UFG::qList<UFG::qPointerNode<UFG::RoadNetworkSegment>,UFG::qPointerNode<UFG::RoadNetworkSegment>,1,0> *)v16;
  }
  else
  {
    v6->mGridNodes = 0i64;
  }
}

// File Line: 147
// RVA: 0xD13A0
__int64 __fastcall UFG::Grid<UFG::RoadNetworkSegment>::Add(UFG::Grid<UFG::RoadNetworkSegment> *this, UFG::RoadNetworkSegment *data, int bucket_index)
{
  unsigned int v3; // esi
  UFG::RoadNetworkSegment *v4; // rdi
  UFG::Grid<UFG::RoadNetworkSegment> *v5; // rbp
  UFG::qList<UFG::qPointerNode<UFG::RoadNetworkSegment>,UFG::qPointerNode<UFG::RoadNetworkSegment>,1,0> *v6; // rbx
  UFG::qNode<UFG::qPointerNode<UFG::RoadNetworkSegment>,UFG::qPointerNode<UFG::RoadNetworkSegment> > *v7; // rax
  char *v8; // rax
  char *v9; // rcx
  UFG::qNode<UFG::qPointerNode<UFG::RoadNetworkSegment>,UFG::qPointerNode<UFG::RoadNetworkSegment> > *v10; // rax

  v3 = bucket_index;
  v4 = data;
  v5 = this;
  v6 = &this->mGridNodes[bucket_index];
  v7 = v6->mNode.mPrev;
  if ( (UFG::qList<UFG::qPointerNode<UFG::RoadNetworkSegment>,UFG::qPointerNode<UFG::RoadNetworkSegment>,1,0> *)v6->mNode.mPrev == v6 )
  {
LABEL_4:
    v8 = UFG::qMalloc(0x18ui64, "grid pointer node", 0i64);
    v9 = v8;
    if ( v8 )
    {
      *(_QWORD *)v8 = v8;
      *((_QWORD *)v8 + 1) = v8;
      *((_QWORD *)v8 + 2) = v4;
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
    ++v5->mNodeCount;
  }
  else
  {
    while ( (UFG::RoadNetworkSegment *)v7[1].mPrev != data )
    {
      v7 = v7->mPrev;
      if ( v7 == (UFG::qNode<UFG::qPointerNode<UFG::RoadNetworkSegment>,UFG::qPointerNode<UFG::RoadNetworkSegment> > *)v6 )
        goto LABEL_4;
    }
  }
  return v3;
}

// File Line: 406
// RVA: 0xCF660
void __fastcall UFG::GridNodesArray<UFG::RoadNetworkSegment>::GridNodesArray<UFG::RoadNetworkSegment>(UFG::GridNodesArray<UFG::RoadNetworkSegment> *this, UFG::Grid<UFG::RoadNetworkSegment> *grid, float x, float y)
{
  float v4; // xmm4_4
  char v5; // r15
  UFG::Grid<UFG::RoadNetworkSegment> *v6; // rbx
  float v7; // xmm1_4
  signed int v8; // er12
  float v9; // xmm3_4
  float v10; // xmm2_4
  signed int v11; // er8
  UFG::qList<UFG::qPointerNode<UFG::RoadNetworkSegment>,UFG::qPointerNode<UFG::RoadNetworkSegment>,1,0> *v12; // rdx
  int v13; // er9
  int v14; // esi
  int v15; // ebp
  int v16; // edi
  __int64 v17; // r14
  __int64 v18; // r11
  int i; // edx
  int v20; // eax
  UFG::qList<UFG::qPointerNode<UFG::RoadNetworkSegment>,UFG::qPointerNode<UFG::RoadNetworkSegment>,1,0> *v21; // r8

  v4 = grid->mXMin;
  v5 = 0;
  v6 = grid;
  if ( x <= v4 )
    x = grid->mXMin;
  if ( x >= grid->mXMax )
    x = grid->mXMax;
  v7 = grid->mYMin;
  if ( y <= v7 )
    y = grid->mYMin;
  if ( y >= grid->mYMax )
    y = grid->mYMax;
  v8 = 3;
  v9 = (float)(y - v7) * grid->mGridSizeInv;
  v10 = (float)(x - v4) * grid->mGridSizeInv;
  this->mNumValidNodes = 0;
  v11 = (signed int)v9;
  v12 = &grid->mGridNodes[(signed int)v10 + (signed int)v9 * grid->mXDim];
  if ( (UFG::qList<UFG::qPointerNode<UFG::RoadNetworkSegment>,UFG::qPointerNode<UFG::RoadNetworkSegment>,1,0> *)v12->mNode.mNext != v12 )
  {
    this->mGridNodeArray[0] = v12;
    ++this->mNumValidNodes;
    v5 = 1;
  }
  while ( 1 )
  {
    v13 = v8 / -2 + (signed int)v10;
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
            v20 = v6->mXDim;
            if ( v13 < v20 && i >= 0 && i < v6->mYDim )
            {
              v21 = &v6->mGridNodes[v13 + i * v20];
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
      v11 = (signed int)v9;
    }
    if ( v5 )
      break;
    v8 += 2;
  }
}

