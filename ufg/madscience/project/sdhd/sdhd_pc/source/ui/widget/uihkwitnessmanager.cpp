// File Line: 33
// RVA: 0x618BA0
void __fastcall UFG::UIHKWitnessManager::Update(UFG::UIHKWitnessManager *this, float elapsed)
{
  UFG::UIHKWitnessManager *v2; // r13
  UFG::UIMapBlipManager *v3; // rsi
  UFG::allocator::free_link *v4; // r15
  unsigned int v5; // ebp
  unsigned int v6; // er14
  UFG::qNode<UFG::UIHKWitnessData,UFG::UIHKWitnessData> *v7; // rdi
  float v8; // xmm0_4
  int v9; // edx
  unsigned int v10; // eax
  __int64 v11; // r12
  unsigned int v12; // esi
  unsigned int v13; // ebx
  unsigned __int64 v14; // rax
  UFG::allocator::free_link *v15; // rax
  UFG::allocator::free_link *v16; // r14
  UFG::allocator::free_link *v17; // rdx
  __int64 v18; // r8
  const char *v19; // rbx
  int v20; // edx
  unsigned int v21; // eax
  UFG::UIMapBlip *v22; // rax
  UFG::allocator::free_link *v23; // rbx
  __int64 v24; // rdi
  UFG::allocator::free_link *v25; // rdx
  UFG::allocator::free_link *v26; // rcx
  UFG::allocator::free_link *v27; // rax
  UFG::allocator::free_link *v28; // rcx
  UFG::allocator::free_link *v29; // rdx
  UFG::allocator::free_link *v30; // rax
  UFG::qString result; // [rsp+48h] [rbp-90h]
  UFG::qString v32; // [rsp+70h] [rbp-68h]
  UFG::UIMapBlipManager *v33; // [rsp+F0h] [rbp+18h]

  v2 = this;
  v3 = UFG::UIHKScreenHud::mIconManager;
  v33 = UFG::UIHKScreenHud::mIconManager;
  if ( UFG::UIHKScreenHud::mIconManager )
  {
    v4 = 0i64;
    v5 = 0;
    v6 = 0;
    v7 = this->mWitnessList.mNode.mNext;
    if ( v7 != (UFG::qNode<UFG::UIHKWitnessData,UFG::UIHKWitnessData> *)this )
    {
      do
      {
        v8 = elapsed + *((float *)&v7[1].mNext + 1);
        *((float *)&v7[1].mNext + 1) = v8;
        if ( v8 <= gWitnessIconLifespan )
        {
          if ( !BYTE4(v7[2].mPrev) )
          {
            v19 = "cop_symbol";
            if ( !BYTE5(v7[2].mPrev) )
              v19 = "witness_symbol";
            LODWORD(v7[2].mPrev) = v2->mNextId++;
            UFG::qString::FormatEx(&v32, "witness%d", LODWORD(v7[2].mPrev));
            v21 = v32.mStringHash32;
            if ( v32.mStringHash32 == -1 )
            {
              v21 = UFG::qStringHash32(v32.mData, v32.mStringHash32 | v20);
              v32.mStringHash32 = v21;
            }
            v22 = UFG::UIMapBlipManager::CreateIcon(
                    v3,
                    v21,
                    v19,
                    *(float *)&v7[1].mPrev,
                    *((float *)&v7[1].mPrev + 1),
                    *((float *)&v7[1].mPrev + 1));
            if ( v22 )
            {
              v22->mHasAltitude = 0;
              UFG::UIMapBlip::Pulse(v22);
              BYTE4(v7[2].mPrev) = 1;
            }
            UFG::qString::~qString(&v32);
          }
        }
        else
        {
          UFG::qString::FormatEx(&result, "witness%d", LODWORD(v7[2].mPrev));
          v10 = result.mStringHash32;
          if ( result.mStringHash32 == -1 )
          {
            v10 = UFG::qStringHash32(result.mData, result.mStringHash32 | v9);
            result.mStringHash32 = v10;
          }
          UFG::UIMapBlipManager::RemoveIcon(v3, v10);
          v11 = v5;
          v12 = v5 + 1;
          if ( v5 + 1 > v6 )
          {
            v13 = 1;
            if ( v6 )
              v13 = 2 * v6;
            for ( ; v13 < v12; v13 *= 2 )
              ;
            if ( v13 <= 2 )
              v13 = 2;
            if ( v13 - v12 > 0x10000 )
              v13 = v5 + 65537;
            if ( v13 != v5 )
            {
              v14 = 8i64 * v13;
              if ( !is_mul_ok(v13, 8ui64) )
                v14 = -1i64;
              v15 = UFG::qMalloc(v14, "qArray.Add", 0i64);
              v16 = v15;
              if ( v4 )
              {
                if ( v5 )
                {
                  v17 = v15;
                  v18 = v5;
                  do
                  {
                    v17->mNext = *(UFG::allocator::free_link **)((char *)v17 + (char *)v4 - (char *)v15);
                    ++v17;
                    --v18;
                  }
                  while ( v18 );
                }
                operator delete[](v4);
              }
              v4 = v16;
              v6 = v13;
            }
          }
          ++v5;
          v4[v11].mNext = (UFG::allocator::free_link *)v7;
          UFG::qString::~qString(&result);
          v3 = v33;
        }
        v7 = v7->mNext;
      }
      while ( v7 != (UFG::qNode<UFG::UIHKWitnessData,UFG::UIHKWitnessData> *)v2 );
    }
    if ( v5 )
    {
      v23 = v4;
      v24 = v5;
      do
      {
        v25 = v23->mNext;
        v26 = v23->mNext->mNext;
        v27 = v23->mNext[1].mNext;
        v26[1].mNext = v27;
        v27->mNext = v26;
        v25->mNext = v25;
        v25[1].mNext = v25;
        v28 = v23->mNext;
        if ( v23->mNext )
        {
          v29 = v28->mNext;
          v30 = v28[1].mNext;
          v29[1].mNext = v30;
          v30->mNext = v29;
          v28->mNext = v28;
          v28[1].mNext = v28;
          operator delete[](v28);
        }
        ++v23;
        --v24;
      }
      while ( v24 );
    }
    if ( v4 )
      operator delete[](v4);
  }
}

// File Line: 80
// RVA: 0x5D2FF0
void __fastcall UFG::UIHKWitnessManager::AddWitness(UFG::UIHKWitnessManager *this, UFG::qVector3 *pos, bool isCop)
{
  bool v3; // si
  UFG::qVector3 *v4; // rdi
  UFG::UIHKWitnessManager *v5; // rbx
  int v6; // ecx
  UFG::UIHKWitnessManager *i; // rax
  UFG::CopSystem *v8; // rax
  UFG::qNode<UFG::UIHKWitnessData,UFG::UIHKWitnessData> *v9; // rax
  UFG::allocator::free_link *v10; // rax
  UFG::allocator::free_link *v11; // rcx
  float v12; // xmm0_4
  float v13; // xmm1_4
  UFG::qNode<UFG::UIHKWitnessData,UFG::UIHKWitnessData> *v14; // rax

  v3 = isCop;
  v4 = pos;
  v5 = this;
  v6 = 0;
  for ( i = (UFG::UIHKWitnessManager *)v5->mWitnessList.mNode.mNext;
        i != v5;
        i = (UFG::UIHKWitnessManager *)i->mWitnessList.mNode.mNext )
  {
    ++v6;
  }
  if ( v6 < gMaxWitnessCount )
  {
    v8 = UFG::CopSystem::Instance();
    if ( ((signed int (__fastcall *)(UFG::CopSystem *))v8->vfptr[89].__vecDelDtor)(v8) <= 0 )
    {
      if ( v3 || (v9 = v5->mWitnessList.mNode.mNext, v9 == (UFG::qNode<UFG::UIHKWitnessData,UFG::UIHKWitnessData> *)v5) )
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
        v12 = v4->y;
        v13 = v4->z;
        *(float *)&v11[2].mNext = v4->x;
        *((float *)&v11[2].mNext + 1) = v12;
        *(float *)&v11[3].mNext = v13;
        BYTE5(v11[4].mNext) = v3;
        v14 = v5->mWitnessList.mNode.mNext;
        v5->mWitnessList.mNode.mNext = (UFG::qNode<UFG::UIHKWitnessData,UFG::UIHKWitnessData> *)v11;
        v11->mNext = (UFG::allocator::free_link *)v5;
        v11[1].mNext = (UFG::allocator::free_link *)v14;
        v14->mPrev = (UFG::qNode<UFG::UIHKWitnessData,UFG::UIHKWitnessData> *)v11;
      }
      else
      {
        while ( (float)((float)((float)((float)(v4->y - *((float *)&v9[1].mPrev + 1))
                                      * (float)(v4->y - *((float *)&v9[1].mPrev + 1)))
                              + (float)((float)(v4->x - *(float *)&v9[1].mPrev) * (float)(v4->x - *(float *)&v9[1].mPrev)))
                      + (float)((float)(v4->z - *(float *)&v9[1].mNext) * (float)(v4->z - *(float *)&v9[1].mNext))) >= (float)(gWitnessSpacing * gWitnessSpacing) )
        {
          v9 = v9->mNext;
          if ( v9 == (UFG::qNode<UFG::UIHKWitnessData,UFG::UIHKWitnessData> *)v5 )
            goto LABEL_12;
        }
        if ( v9 )
          HIDWORD(v9[1].mNext) = 0;
      }
    }
  }
}

