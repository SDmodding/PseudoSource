// File Line: 33
// RVA: 0x618BA0
void __fastcall UFG::UIHKWitnessManager::Update(UFG::UIHKWitnessManager *this, float elapsed)
{
  UFG::UIMapBlipManager *v3; // rsi
  UFG::allocator::free_link *v4; // r15
  unsigned int v5; // ebp
  unsigned int v6; // r14d
  UFG::qNode<UFG::UIHKWitnessData,UFG::UIHKWitnessData> *i; // rdi
  float v8; // xmm0_4
  unsigned int v9; // eax
  __int64 v10; // r12
  unsigned int v11; // esi
  unsigned int v12; // ebx
  unsigned __int64 v13; // rax
  UFG::allocator::free_link *v14; // rax
  UFG::allocator::free_link *v15; // r14
  UFG::allocator::free_link *v16; // rdx
  __int64 v17; // r8
  const char *v18; // rbx
  unsigned int mStringHash32; // eax
  UFG::UIMapBlip *Icon; // rax
  UFG::allocator::free_link *v21; // rbx
  __int64 v22; // rdi
  UFG::allocator::free_link *mNext; // rdx
  UFG::allocator::free_link *v24; // rcx
  UFG::allocator::free_link *v25; // rax
  UFG::allocator::free_link *v26; // rcx
  UFG::allocator::free_link *v27; // rdx
  UFG::allocator::free_link *v28; // rax
  UFG::qString result; // [rsp+48h] [rbp-90h] BYREF
  UFG::qString v30; // [rsp+70h] [rbp-68h] BYREF
  UFG::UIMapBlipManager *v31; // [rsp+F0h] [rbp+18h]

  v3 = UFG::UIHKScreenHud::mIconManager;
  v31 = UFG::UIHKScreenHud::mIconManager;
  if ( UFG::UIHKScreenHud::mIconManager )
  {
    v4 = 0i64;
    v5 = 0;
    v6 = 0;
    for ( i = this->mWitnessList.mNode.mNext;
          i != (UFG::qNode<UFG::UIHKWitnessData,UFG::UIHKWitnessData> *)this;
          i = i->mNext )
    {
      v8 = elapsed + *((float *)&i[1].mNext + 1);
      *((float *)&i[1].mNext + 1) = v8;
      if ( v8 <= gWitnessIconLifespan )
      {
        if ( !BYTE4(i[2].mPrev) )
        {
          v18 = "cop_symbol";
          if ( !BYTE5(i[2].mPrev) )
            v18 = "witness_symbol";
          LODWORD(i[2].mPrev) = this->mNextId++;
          UFG::qString::FormatEx(&v30, "witness%d", LODWORD(i[2].mPrev));
          mStringHash32 = v30.mStringHash32;
          if ( v30.mStringHash32 == -1 )
          {
            mStringHash32 = UFG::qStringHash32(v30.mData, 0xFFFFFFFF);
            v30.mStringHash32 = mStringHash32;
          }
          Icon = UFG::UIMapBlipManager::CreateIcon(
                   v3,
                   mStringHash32,
                   v18,
                   *(float *)&i[1].mPrev,
                   *((float *)&i[1].mPrev + 1));
          if ( Icon )
          {
            Icon->mHasAltitude = 0;
            UFG::UIMapBlip::Pulse(Icon);
            BYTE4(i[2].mPrev) = 1;
          }
          UFG::qString::~qString(&v30);
        }
      }
      else
      {
        UFG::qString::FormatEx(&result, "witness%d", LODWORD(i[2].mPrev));
        v9 = result.mStringHash32;
        if ( result.mStringHash32 == -1 )
        {
          v9 = UFG::qStringHash32(result.mData, 0xFFFFFFFF);
          result.mStringHash32 = v9;
        }
        UFG::UIMapBlipManager::RemoveIcon(v3, v9);
        v10 = v5;
        v11 = v5 + 1;
        if ( v5 + 1 > v6 )
        {
          v12 = 1;
          if ( v6 )
            v12 = 2 * v6;
          for ( ; v12 < v11; v12 *= 2 )
            ;
          if ( v12 <= 2 )
            v12 = 2;
          if ( v12 - v11 > 0x10000 )
            v12 = v5 + 65537;
          if ( v12 != v5 )
          {
            v13 = 8i64 * v12;
            if ( !is_mul_ok(v12, 8ui64) )
              v13 = -1i64;
            v14 = UFG::qMalloc(v13, "qArray.Add", 0i64);
            v15 = v14;
            if ( v4 )
            {
              if ( v5 )
              {
                v16 = v14;
                v17 = v5;
                do
                {
                  v16->mNext = *(UFG::allocator::free_link **)((char *)v16 + (char *)v4 - (char *)v14);
                  ++v16;
                  --v17;
                }
                while ( v17 );
              }
              operator delete[](v4);
            }
            v4 = v15;
            v6 = v12;
          }
        }
        ++v5;
        v4[v10].mNext = (UFG::allocator::free_link *)i;
        UFG::qString::~qString(&result);
        v3 = v31;
      }
    }
    if ( v5 )
    {
      v21 = v4;
      v22 = v5;
      do
      {
        mNext = v21->mNext;
        v24 = v21->mNext->mNext;
        v25 = v21->mNext[1].mNext;
        v24[1].mNext = v25;
        v25->mNext = v24;
        mNext->mNext = mNext;
        mNext[1].mNext = mNext;
        v26 = v21->mNext;
        if ( v21->mNext )
        {
          v27 = v26->mNext;
          v28 = v26[1].mNext;
          v27[1].mNext = v28;
          v28->mNext = v27;
          v26->mNext = v26;
          v26[1].mNext = v26;
          operator delete[](v26);
        }
        ++v21;
        --v22;
      }
      while ( v22 );
    }
    if ( v4 )
      operator delete[](v4);
  }
}

// File Line: 80
// RVA: 0x5D2FF0
void __fastcall UFG::UIHKWitnessManager::AddWitness(UFG::UIHKWitnessManager *this, UFG::qVector3 *pos, bool isCop)
{
  int v6; // ecx
  UFG::UIHKWitnessManager *i; // rax
  UFG::CopSystem *v8; // rax
  UFG::qNode<UFG::UIHKWitnessData,UFG::UIHKWitnessData> *v9; // rax
  UFG::allocator::free_link *v10; // rax
  UFG::allocator::free_link *v11; // rcx
  float y; // xmm0_4
  float z; // xmm1_4
  UFG::qNode<UFG::UIHKWitnessData,UFG::UIHKWitnessData> *mNext; // rax

  v6 = 0;
  for ( i = (UFG::UIHKWitnessManager *)this->mWitnessList.mNode.mNext;
        i != this;
        i = (UFG::UIHKWitnessManager *)i->mWitnessList.mNode.mNext )
  {
    ++v6;
  }
  if ( v6 < gMaxWitnessCount )
  {
    v8 = UFG::CopSystem::Instance();
    if ( ((int (__fastcall *)(UFG::CopSystem *))v8->vfptr[89].__vecDelDtor)(v8) <= 0 )
    {
      if ( isCop
        || (v9 = this->mWitnessList.mNode.mNext, v9 == (UFG::qNode<UFG::UIHKWitnessData,UFG::UIHKWitnessData> *)this) )
      {
LABEL_12:
        v10 = UFG::qMalloc(0x28ui64, "UIHKWitnessData", 0i64);
        v11 = v10;
        if ( v10 )
        {
          v10->mNext = v10;
          v10[1].mNext = v10;
          *(UFG::allocator::free_link **)((char *)&v10[3].mNext + 4) = 0i64;
          WORD2(v10[4].mNext) = 0;
        }
        else
        {
          v11 = 0i64;
        }
        y = pos->y;
        z = pos->z;
        *(float *)&v11[2].mNext = pos->x;
        *((float *)&v11[2].mNext + 1) = y;
        *(float *)&v11[3].mNext = z;
        BYTE5(v11[4].mNext) = isCop;
        mNext = this->mWitnessList.mNode.mNext;
        this->mWitnessList.mNode.mNext = (UFG::qNode<UFG::UIHKWitnessData,UFG::UIHKWitnessData> *)v11;
        v11->mNext = (UFG::allocator::free_link *)this;
        v11[1].mNext = (UFG::allocator::free_link *)mNext;
        mNext->mPrev = (UFG::qNode<UFG::UIHKWitnessData,UFG::UIHKWitnessData> *)v11;
      }
      else
      {
        while ( (float)((float)((float)((float)(pos->y - *((float *)&v9[1].mPrev + 1))
                                      * (float)(pos->y - *((float *)&v9[1].mPrev + 1)))
                              + (float)((float)(pos->x - *(float *)&v9[1].mPrev)
                                      * (float)(pos->x - *(float *)&v9[1].mPrev)))
                      + (float)((float)(pos->z - *(float *)&v9[1].mNext) * (float)(pos->z - *(float *)&v9[1].mNext))) >= (float)(gWitnessSpacing * gWitnessSpacing) )
        {
          v9 = v9->mNext;
          if ( v9 == (UFG::qNode<UFG::UIHKWitnessData,UFG::UIHKWitnessData> *)this )
            goto LABEL_12;
        }
        if ( v9 )
          HIDWORD(v9[1].mNext) = 0;
      }
    }
  }
}

