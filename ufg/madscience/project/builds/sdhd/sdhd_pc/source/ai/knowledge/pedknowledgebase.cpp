// File Line: 23
// RVA: 0x14AD380
__int64 dynamic_initializer_for__UFG::PedKnowledgeBase::ms_defaultKnowledgeRecord__()
{
  UFG::PedKnowledgeBase::ms_defaultKnowledgeRecord.pSimObject.m_pPointer = 0i64;
  UFG::PedKnowledgeBase::ms_defaultKnowledgeRecord.m_uLastTimeSeen = 0i64;
  UFG::PedKnowledgeBase::ms_defaultKnowledgeRecord.m_uLastLOSTest = 0i64;
  UFG::PedKnowledgeBase::ms_defaultKnowledgeRecord.m_uLastPathTest = 0i64;
  *((_BYTE *)&UFG::PedKnowledgeBase::ms_defaultKnowledgeRecord + 48) = *((_BYTE *)&UFG::PedKnowledgeBase::ms_defaultKnowledgeRecord
                                                                       + 48) & 0xF8 | 4;
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::PedKnowledgeBase::ms_defaultKnowledgeRecord__);
}

// File Line: 89
// RVA: 0x391870
void __fastcall UFG::PedKnowledgeBase::Update(UFG::PedKnowledgeBase *this, float fDeltaTime)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::ActiveAIEntityComponent *v5; // rax
  UFG::TransformNodeComponent *m_pSimComponent; // rbx
  unsigned int size; // r14d
  UFG::qVector3 *v8; // r15
  unsigned int v9; // ebx
  __int64 v10; // rdi
  UFG::PedKnowledgeRecord *v11; // rbp
  float fPriority; // xmm0_4

  if ( this->m_bEnabled )
  {
    m_pPointer = (UFG::SimObjectCVBase *)this->m_pParentSimObject.m_pPointer;
    if ( m_pPointer )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
        v5 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(m_pPointer);
      else
        v5 = (UFG::ActiveAIEntityComponent *)((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                            ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                m_pPointer,
                                                UFG::ActiveAIEntityComponent::_TypeUID)
                                            : UFG::SimObject::GetComponentOfType(
                                                m_pPointer,
                                                UFG::ActiveAIEntityComponent::_TypeUID));
      if ( v5 )
      {
        m_pSimComponent = (UFG::TransformNodeComponent *)v5->m_pTransformNodeComponent.m_pSimComponent;
        UFG::TransformNodeComponent::UpdateWorldTransform(m_pSimComponent);
        size = this->m_aHostilePedRecords.size;
        v8 = (UFG::qVector3 *)&m_pSimComponent->mWorldTransform.v3;
        v9 = 0;
        if ( size )
        {
          v10 = 0i64;
          do
          {
            v11 = &this->m_aHostilePedRecords.p[v10];
            if ( v11->pSimObject.m_pPointer )
            {
              fPriority = UFG::PedKnowledgeBase::GetLineOfSightPriority(this, v8, &this->m_aHostilePedRecords.p[v10]);
              UFG::PedKnowledgeLOSSystem::AddTest(
                UFG::PedKnowledgeLOSSystem::ms_pInstance,
                this->m_pParentSimObject.m_pPointer,
                v11->pSimObject.m_pPointer,
                v9,
                fPriority);
            }
            ++v9;
            ++v10;
          }
          while ( v9 < size );
        }
      }
    }
  }
}

// File Line: 117
// RVA: 0x340B90
void __fastcall UFG::PedKnowledgeBase::AddRecordForHostile(
        UFG::PedKnowledgeBase *this,
        UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *pNewHostile)
{
  __int64 size; // rbp
  UFG::qArray<UFG::PedKnowledgeRecord,15> *p_m_aHostilePedRecords; // rbx
  unsigned int v5; // esi
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *p_pSimObject; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rax

  size = this->m_aHostilePedRecords.size;
  p_m_aHostilePedRecords = &this->m_aHostilePedRecords;
  v5 = size + 1;
  if ( (unsigned int)(size + 1) > this->m_aHostilePedRecords.capacity )
    UFG::qArray<UFG::PedKnowledgeRecord,15>::Reallocate(
      &this->m_aHostilePedRecords,
      15 * (v5 / 0xF + (v5 != 15 * (v5 / 0xF))),
      "qArray.Add");
  p_m_aHostilePedRecords->size = v5;
  p_pSimObject = &p_m_aHostilePedRecords->p[size].pSimObject;
  if ( p_pSimObject[1].mPrev )
  {
    mPrev = p_pSimObject->mPrev;
    mNext = p_pSimObject->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_pSimObject->mPrev = p_pSimObject;
    p_pSimObject->mNext = p_pSimObject;
  }
  p_pSimObject[1].mPrev = pNewHostile;
  if ( pNewHostile )
  {
    v9 = pNewHostile->mNext;
    v9->mNext = p_pSimObject;
    p_pSimObject->mPrev = v9;
    p_pSimObject->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&pNewHostile->mNext;
    pNewHostile->mNext = p_pSimObject;
  }
}

// File Line: 123
// RVA: 0x380350
void __fastcall UFG::PedKnowledgeBase::RefreshHostileList(UFG::PedKnowledgeBase *this, float fDeltaTime)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::ActiveAIEntityComponent *v5; // rax
  UFG::ActiveAIEntityComponent *v6; // r13
  UFG::NearbyCharacterManager *v7; // r8
  __int64 **v8; // rbx
  __int64 **v9; // rax
  __int64 **v10; // r12
  _QWORD *v11; // rdx
  __int64 *v12; // rcx
  __int64 *v13; // rax
  UFG::NearbyCharacterManager *mNext; // rcx
  __int64 *v15; // rdx
  __int64 v16; // r14
  __int64 i; // rbx
  __int64 v18; // rsi
  UFG::AttackRightsComponent *v19; // r15
  unsigned int size; // ebx
  __int64 *v21; // rsi
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v22; // rdx
  unsigned int v23; // ecx
  UFG::SimObject **p_m_pPointer; // rax
  __int64 v25; // r9
  __int64 v26; // r11
  UFG::PedKnowledgeRecord *p; // rcx
  UFG::PedKnowledgeRecord *v28; // r8
  UFG::PedKnowledgeRecord *v29; // rdx
  UFG::SimObject *v30; // r10
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v32; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v33; // rax
  char v34; // cl
  unsigned int v35; // eax
  __int64 **j; // rax
  _QWORD *v37; // rdx
  __int64 *v38; // rcx
  __int64 *v39; // rax
  __int64 *v40; // rcx
  __int64 **v41; // rax
  __int64 v42; // [rsp+0h] [rbp-D8h] BYREF
  _BYTE v43[16]; // [rsp+10h] [rbp-C8h] BYREF
  __int64 *v44; // [rsp+20h] [rbp-B8h] BYREF
  __int64 **v45; // [rsp+28h] [rbp-B0h]
  __int64 v46; // [rsp+30h] [rbp-A8h]
  char dest[24]; // [rsp+40h] [rbp-98h] BYREF
  __int64 v48[69]; // [rsp+58h] [rbp-80h] BYREF

  v46 = -2i64;
  if ( this->m_bEnabled )
  {
    m_pPointer = (UFG::SimObjectCVBase *)this->m_pParentSimObject.m_pPointer;
    if ( m_pPointer )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
        v5 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(m_pPointer);
      else
        v5 = (UFG::ActiveAIEntityComponent *)((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                            ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                m_pPointer,
                                                UFG::ActiveAIEntityComponent::_TypeUID)
                                            : UFG::SimObject::GetComponentOfType(
                                                m_pPointer,
                                                UFG::ActiveAIEntityComponent::_TypeUID));
      v6 = v5;
      if ( v5 )
      {
        UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v5->m_pTransformNodeComponent.m_pSimComponent);
        v44 = (__int64 *)&v44;
        v45 = &v44;
        v7 = UFG::NearbyCharacterManager::s_pInstance;
        v8 = &v44;
        v9 = (__int64 **)v43;
        v10 = (__int64 **)(&v42 + 2);
        if ( v43 != (_BYTE *)v10 )
        {
          do
          {
            v11 = v9 + 2;
            v12 = v9[2];
            v13 = v9[3];
            v12[1] = (__int64)v13;
            *v13 = (__int64)v12;
            *v11 = v11;
            v11[1] = v11;
            v8 = v45;
            v9 = v45 - 2;
          }
          while ( v45 - 2 != v10 );
        }
        mNext = (UFG::NearbyCharacterManager *)v7->m_Characters[0].mNode.mNext;
        if ( mNext != v7 )
        {
          v15 = v44;
          do
          {
            v15[1] = (__int64)&mNext->m_Characters[1];
            mNext->m_Characters[1].mNode.mPrev = (UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterMasterList> *)v15;
            mNext->m_Characters[1].mNode.mNext = (UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterMasterList> *)&v44;
            v15 = (__int64 *)&mNext->m_Characters[1];
            v44 = (__int64 *)&mNext->m_Characters[1];
            mNext = (UFG::NearbyCharacterManager *)mNext->m_Characters[0].mNode.mNext;
          }
          while ( mNext != v7 );
          v8 = v45;
        }
        v16 = 0i64;
        for ( i = (__int64)(v8 - 2); (__int64 **)i != v10; i = *(_QWORD *)(i + 24) - 16i64 )
        {
          v18 = *(_QWORD *)(i + 48);
          if ( v18 )
          {
            v19 = *(UFG::AttackRightsComponent **)(v18 + 328);
            if ( UFG::ActiveAIEntityComponent::IsEnemyOfMine(v6, v19)
              && v19
              && UFG::ActiveAIEntityComponent::CanBeEngagedShared(v6, v19) )
            {
              v48[v16] = *(_QWORD *)(v18 + 40);
              v16 = (unsigned int)(v16 + 1);
            }
          }
        }
        UFG::qMemSet(dest, 0, 0x40u);
        size = this->m_aHostilePedRecords.size;
        if ( (_DWORD)v16 )
        {
          v21 = v48;
          do
          {
            v22 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)*v21;
            v23 = 0;
            if ( size )
            {
              p_m_pPointer = &this->m_aHostilePedRecords.p->pSimObject.m_pPointer;
              while ( v22 != (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)*p_m_pPointer )
              {
                ++v23;
                p_m_pPointer += 7;
                if ( v23 >= size )
                  goto LABEL_32;
              }
              dest[v23] = 1;
            }
            else
            {
LABEL_32:
              UFG::PedKnowledgeBase::AddRecordForHostile(this, v22);
            }
            ++v21;
            --v16;
          }
          while ( v16 );
        }
        v25 = (int)(size - 1);
        if ( (int)(size - 1) >= 0 )
        {
          v26 = (int)(size - 1);
          do
          {
            if ( !dest[v25] )
            {
              p = this->m_aHostilePedRecords.p;
              v28 = &p[this->m_aHostilePedRecords.size - 1];
              v29 = &p[v26];
              v30 = v28->pSimObject.m_pPointer;
              if ( p[v26].pSimObject.m_pPointer )
              {
                mPrev = v29->pSimObject.mPrev;
                v32 = v29->pSimObject.mNext;
                mPrev->mNext = v32;
                v32->mPrev = mPrev;
                v29->pSimObject.mPrev = &v29->pSimObject;
                v29->pSimObject.mNext = &v29->pSimObject;
              }
              v29->pSimObject.m_pPointer = v30;
              if ( v30 )
              {
                v33 = v30->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
                v33->mNext = &v29->pSimObject;
                v29->pSimObject.mPrev = v33;
                v29->pSimObject.mNext = &v30->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
                v30->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = &v29->pSimObject;
              }
              v29->m_uLastTimeSeen = v28->m_uLastTimeSeen;
              v29->m_uLastLOSTest = v28->m_uLastLOSTest;
              v29->m_uLastPathTest = v28->m_uLastPathTest;
              *((_BYTE *)v29 + 48) ^= (*((_BYTE *)v28 + 48) ^ *((_BYTE *)v29 + 48)) & 1;
              v34 = *((_BYTE *)v29 + 48) ^ (*((_BYTE *)v28 + 48) ^ *((_BYTE *)v29 + 48)) & 2;
              *((_BYTE *)v29 + 48) = v34;
              *((_BYTE *)v29 + 48) = v34 ^ (*((_BYTE *)v28 + 48) ^ v34) & 4;
              v35 = this->m_aHostilePedRecords.size;
              if ( v35 > 1 )
                this->m_aHostilePedRecords.size = v35 - 1;
              else
                this->m_aHostilePedRecords.size = 0;
            }
            --v26;
            --v25;
          }
          while ( v25 >= 0 );
        }
        for ( j = v45 - 2; v45 - 2 != v10; j = v45 - 2 )
        {
          v37 = j + 2;
          v38 = j[2];
          v39 = j[3];
          v38[1] = (__int64)v39;
          *v39 = (__int64)v38;
          *v37 = v37;
          v37[1] = v37;
        }
        v40 = v44;
        v41 = v45;
        v44[1] = (__int64)v45;
        *v41 = v40;
      }
    }
  }
}

// File Line: 204
// RVA: 0x379160
void __fastcall UFG::PedKnowledgeBase::OnAttach(UFG::PedKnowledgeBase *this, UFG::SimObject *pParentSimObj)
{
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rax
  UFG::PedKnowledgeRecord *p; // rcx
  void *v7; // rbx
  fastdelegate::FastDelegate1<float,void> v8; // [rsp+20h] [rbp-18h] BYREF

  if ( this->m_pParentSimObject.m_pPointer )
  {
    mPrev = this->m_pParentSimObject.mPrev;
    mNext = this->m_pParentSimObject.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->m_pParentSimObject.mPrev = &this->m_pParentSimObject;
    this->m_pParentSimObject.mNext = &this->m_pParentSimObject;
  }
  this->m_pParentSimObject.m_pPointer = pParentSimObj;
  if ( pParentSimObj )
  {
    v5 = pParentSimObj->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
    v5->mNext = &this->m_pParentSimObject;
    this->m_pParentSimObject.mPrev = v5;
    this->m_pParentSimObject.mNext = &pParentSimObj->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
    pParentSimObj->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = &this->m_pParentSimObject;
  }
  v8.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))UFG::PedKnowledgeBase::RefreshHostileList;
  v8.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)this;
  UFG::TicketBoothManager::Register(UFG::TicketBoothManager::mpSingleton, 6, &this->m_ticketRefreshHostiles, &v8);
  v8.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)this;
  v8.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))UFG::PedKnowledgeBase::Update;
  UFG::TicketBoothManager::Register(UFG::TicketBoothManager::mpSingleton, 7, &this->m_ticketUpdate, &v8);
  this->m_bEnabled = 1;
  p = this->m_aHostilePedRecords.p;
  if ( p )
  {
    v7 = (char *)&p[-1] + 48;
    `eh vector destructor iterator(
      p,
      0x38ui64,
      *((_DWORD *)&p[-1] + 12),
      (void (__fastcall *)(void *))UFG::InterestPointUseDetails::~InterestPointUseDetails);
    operator delete[](v7);
  }
  this->m_aHostilePedRecords.p = 0i64;
  *(_QWORD *)&this->m_aHostilePedRecords.size = 0i64;
  UFG::PedKnowledgeBase::RefreshHostileList(this, 0.0);
}

// File Line: 214
// RVA: 0x37B000
void __fastcall UFG::PedKnowledgeBase::OnDetach(UFG::PedKnowledgeBase *this)
{
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::PedKnowledgeRecord *p; // rcx
  void *v5; // rbx

  if ( this->m_pParentSimObject.m_pPointer )
  {
    mPrev = this->m_pParentSimObject.mPrev;
    mNext = this->m_pParentSimObject.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->m_pParentSimObject.mPrev = &this->m_pParentSimObject;
    this->m_pParentSimObject.mNext = &this->m_pParentSimObject;
  }
  this->m_pParentSimObject.m_pPointer = 0i64;
  UFG::TicketBoothManager::Unregister(
    UFG::TicketBoothManager::mpSingleton,
    TICKETBOOTH_KNOWLEDGEBASE_REFRESHHOSTILES,
    &this->m_ticketRefreshHostiles);
  UFG::TicketBoothManager::Unregister(
    UFG::TicketBoothManager::mpSingleton,
    TICKETBOOTH_KNOWLEDGEBASE_UPDATE,
    &this->m_ticketUpdate);
  p = this->m_aHostilePedRecords.p;
  if ( p )
  {
    v5 = (char *)&p[-1] + 48;
    `eh vector destructor iterator(
      p,
      0x38ui64,
      *((_DWORD *)&p[-1] + 12),
      (void (__fastcall *)(void *))UFG::InterestPointUseDetails::~InterestPointUseDetails);
    operator delete[](v5);
  }
  this->m_aHostilePedRecords.p = 0i64;
  *(_QWORD *)&this->m_aHostilePedRecords.size = 0i64;
}

// File Line: 225
// RVA: 0x360AD0
float __fastcall UFG::PedKnowledgeBase::GetLineOfSightPriority(
        UFG::PedKnowledgeBase *this,
        UFG::qVector3 *vMyPos,
        UFG::PedKnowledgeRecord *pedKnowledgeRecord)
{
  UFG::TransformNodeComponent *m_pPointer; // rbx
  __m128 y_low; // xmm2
  float v7; // xmm3_4
  float v8; // xmm1_4
  float v9; // xmm0_4

  m_pPointer = (UFG::TransformNodeComponent *)pedKnowledgeRecord->pSimObject.m_pPointer;
  if ( m_pPointer )
    m_pPointer = (UFG::TransformNodeComponent *)m_pPointer->mChildren.mNode.mNext;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pPointer);
  y_low = (__m128)LODWORD(vMyPos->y);
  v7 = FLOAT_0_0099999998;
  y_low.m128_f32[0] = (float)((float)((float)(y_low.m128_f32[0] - m_pPointer->mWorldTransform.v3.y)
                                    * (float)(y_low.m128_f32[0] - m_pPointer->mWorldTransform.v3.y))
                            + (float)((float)(vMyPos->x - m_pPointer->mWorldTransform.v3.x)
                                    * (float)(vMyPos->x - m_pPointer->mWorldTransform.v3.x)))
                    + (float)((float)(vMyPos->z - m_pPointer->mWorldTransform.v3.z)
                            * (float)(vMyPos->z - m_pPointer->mWorldTransform.v3.z));
  v8 = _mm_sqrt_ps(y_low).m128_f32[0];
  if ( v8 >= 0.0099999998 )
    v7 = v8;
  v9 = (float)(LODWORD(UFG::Metrics::msInstance.mSimTimeMSec) - LODWORD(pedKnowledgeRecord->m_uLastLOSTest));
  if ( (__int64)(UFG::Metrics::msInstance.mSimTimeMSec - pedKnowledgeRecord->m_uLastLOSTest) < 0 )
    v9 = v9 + 1.8446744e19;
  return (float)((float)(v9 * 0.001) * UFG::PedKnowledgeBase::ms_fTimePriority)
       + (float)((float)(1.0 / v7) * UFG::PedKnowledgeBase::ms_fDistancePriority);
}

