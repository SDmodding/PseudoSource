// File Line: 59
// RVA: 0x1554AC0
__int64 dynamic_initializer_for__UFG::DialogueAnimationComponent::s_DialogueAnimationComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::DialogueAnimationComponent::s_DialogueAnimationComponentList__);
}

// File Line: 60
// RVA: 0x1554850
__int64 dynamic_initializer_for__UFG::DialogueAnimationComponent::_TypeIDesc__()
{
  UFG::ComponentIDDesc *v0; // rax
  __int64 result; // rax

  v0 = UFG::DialogueAnimationComponent::AccessComponentDesc();
  *(_DWORD *)&UFG::DialogueAnimationComponent::_TypeIDesc.mBaseTypeIndex = *(_DWORD *)&v0->mBaseTypeIndex;
  UFG::DialogueAnimationComponent::_TypeIDesc.mChildBitMask = v0->mChildBitMask;
  result = v0->mChildren;
  UFG::DialogueAnimationComponent::_TypeIDesc.mChildren = result;
  return result;
}

// File Line: 81
// RVA: 0x593340
void __fastcall UFG::DialogueAnimationComponent::DialogueAnimationComponent(UFG::DialogueAnimationComponent *this, UFG::SceneObjectProperties *pSceneObj)
{
  UFG::DialogueAnimationComponent *v2; // rbx
  UFG::qNode<UFG::DialogueAnimationComponent,UFG::DialogueAnimationComponent> *v3; // rdx
  UFG::qNode<UFG::DialogueAnimationComponent,UFG::DialogueAnimationComponent> *v4; // rax
  char v5; // cl
  UFG::qSafePointer<PoseNode,PoseNode> *v6; // [rsp+48h] [rbp+10h]
  UFG::qSafePointer<AnimationNode,AnimationNode> *v7; // [rsp+48h] [rbp+10h]

  v2 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, pSceneObj->m_NameUID);
  v3 = (UFG::qNode<UFG::DialogueAnimationComponent,UFG::DialogueAnimationComponent> *)&v2->mPrev;
  v3->mPrev = v3;
  v3->mNext = v3;
  v2->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::DialogueAnimationComponent::`vftable';
  v2->m_currentTime = 0.0;
  *(_WORD *)&v2->m_parametricMode = 0;
  *(_QWORD *)&v2->m_sampleNameHash = 0i64;
  v2->m_animName.mUID = -1;
  v6 = &v2->m_splitBodyBlend;
  v6->mPrev = (UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *)&v6->mPrev;
  v6->mNext = (UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *)&v6->mPrev;
  v2->m_splitBodyBlend.m_pPointer = 0i64;
  v7 = &v2->m_controller;
  v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  v7->mNext = (UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  v2->m_controller.m_pPointer = 0i64;
  v2->mFacialContext = 0i64;
  *((_BYTE *)v2 + 168) = *((_BYTE *)v2 + 168) & 0xF9 | 1;
  v2->mActionRequests.mBits[0] = 0i64;
  v2->mActionRequests.mBits[1] = 0i64;
  v2->mActionRequests.mBits[2] = 0i64;
  v2->mActionRequests.mBits[3] = 0i64;
  v2->mActionRequests.mBits[4] = 0i64;
  v2->mActionRequests.mBits[5] = 0i64;
  v2->mActionRequests.mBits[6] = 0i64;
  v2->mActionRequests.mBits[7] = 0i64;
  v2->mActionRequests.mBits[8] = 0i64;
  v4 = UFG::DialogueAnimationComponent::s_DialogueAnimationComponentList.mNode.mPrev;
  UFG::DialogueAnimationComponent::s_DialogueAnimationComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::DialogueAnimationComponent,UFG::DialogueAnimationComponent> *)&v2->mPrev;
  v3->mPrev = v4;
  v2->mNext = (UFG::qNode<UFG::DialogueAnimationComponent,UFG::DialogueAnimationComponent> *)&UFG::DialogueAnimationComponent::s_DialogueAnimationComponentList;
  UFG::DialogueAnimationComponent::s_DialogueAnimationComponentList.mNode.mPrev = (UFG::qNode<UFG::DialogueAnimationComponent,UFG::DialogueAnimationComponent> *)&v2->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v2->vfptr,
    UFG::DialogueAnimationComponent::_DialogueAnimationComponentTypeUID,
    "DialogueAnimationComponent");
  v5 = UFG::DialogueAnimationComponent::sm_tweakInit;
  if ( !UFG::DialogueAnimationComponent::sm_tweakInit )
    v5 = 1;
  UFG::DialogueAnimationComponent::sm_tweakInit = v5;
}

// File Line: 102
// RVA: 0x5943F0
void __fastcall UFG::DialogueAnimationComponent::~DialogueAnimationComponent(UFG::DialogueAnimationComponent *this)
{
  UFG::DialogueAnimationComponent *v1; // r8
  UFG::qNode<UFG::DialogueAnimationComponent,UFG::DialogueAnimationComponent> *v2; // r9
  UFG::qNode<UFG::DialogueAnimationComponent,UFG::DialogueAnimationComponent> *v3; // rcx
  UFG::qNode<UFG::DialogueAnimationComponent,UFG::DialogueAnimationComponent> *v4; // rax
  UFG::qSafePointer<AnimationNode,AnimationNode> *v5; // rdx
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qSafePointer<PoseNode,PoseNode> *v10; // rdx
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *v11; // rcx
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::DialogueAnimationComponent,UFG::DialogueAnimationComponent> *v15; // rcx
  UFG::qNode<UFG::DialogueAnimationComponent,UFG::DialogueAnimationComponent> *v16; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::DialogueAnimationComponent::`vftable';
  if ( this == UFG::DialogueAnimationComponent::s_DialogueAnimationComponentpCurrentIterator )
    UFG::DialogueAnimationComponent::s_DialogueAnimationComponentpCurrentIterator = (UFG::DialogueAnimationComponent *)&this->mPrev[-4];
  v2 = (UFG::qNode<UFG::DialogueAnimationComponent,UFG::DialogueAnimationComponent> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  v5 = &v1->m_controller;
  if ( v1->m_controller.m_pPointer )
  {
    v6 = v5->mPrev;
    v7 = v1->m_controller.mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *)&v5->mPrev;
    v1->m_controller.mNext = (UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *)&v1->m_controller.mPrev;
  }
  v1->m_controller.m_pPointer = 0i64;
  v8 = v5->mPrev;
  v9 = v1->m_controller.mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  v1->m_controller.mNext = (UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *)&v1->m_controller.mPrev;
  v10 = &v1->m_splitBodyBlend;
  if ( v1->m_splitBodyBlend.m_pPointer )
  {
    v11 = v10->mPrev;
    v12 = v1->m_splitBodyBlend.mNext;
    v11->mNext = v12;
    v12->mPrev = v11;
    v10->mPrev = (UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *)&v10->mPrev;
    v1->m_splitBodyBlend.mNext = (UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *)&v1->m_splitBodyBlend.mPrev;
  }
  v1->m_splitBodyBlend.m_pPointer = 0i64;
  v13 = v10->mPrev;
  v14 = v1->m_splitBodyBlend.mNext;
  v13->mNext = v14;
  v14->mPrev = v13;
  v10->mPrev = (UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *)&v10->mPrev;
  v1->m_splitBodyBlend.mNext = (UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *)&v1->m_splitBodyBlend.mPrev;
  v15 = v2->mPrev;
  v16 = v2->mNext;
  v15->mNext = v16;
  v16->mPrev = v15;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

// File Line: 110
// RVA: 0x5A87D0
UFG::SimComponent *__fastcall UFG::DialogueAnimationComponent::PropertiesOnActivateNew(UFG::SceneObjectProperties *pSceneObj, bool required)
{
  UFG::SceneObjectProperties *v2; // rbx
  UFG::qMemoryPool *v3; // rax
  UFG::allocator::free_link *v4; // rax
  UFG::SimComponent *v5; // rax
  UFG::SimComponent *v6; // rdi
  UFG::SimObject *v7; // rdx
  unsigned int v8; // ebx
  UFG::SimObjectModifier v10; // [rsp+38h] [rbp-30h]

  v2 = pSceneObj;
  v3 = UFG::GetSimulationMemoryPool();
  v4 = UFG::qMemoryPool::Allocate(v3, 0xF8ui64, "DialogueAnimationComponent", 0i64, 1u);
  if ( v4 )
  {
    UFG::DialogueAnimationComponent::DialogueAnimationComponent((UFG::DialogueAnimationComponent *)v4, v2);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  v7 = v2->m_pSimObject;
  if ( (v7->m_Flags >> 14) & 1 )
    v8 = 41;
  else
    v8 = -1;
  UFG::SimObjectModifier::SimObjectModifier(&v10, v7, 1);
  UFG::SimObjectModifier::AttachComponent(&v10, v6, v8);
  UFG::SimObjectModifier::Close(&v10);
  UFG::SimObjectModifier::~SimObjectModifier(&v10);
  return v6;
}

// File Line: 118
// RVA: 0x5A3990
void __fastcall UFG::DialogueAnimationComponent::OnAttach(UFG::DialogueAnimationComponent *this, UFG::SimObject *object)
{
  if ( (UFG::SimObjectCharacter *)this->m_pSimObject == LocalPlayer )
    *((_BYTE *)this + 168) |= 2u;
  this->mActionRequests.mBits[0] = 0i64;
  this->mActionRequests.mBits[1] = 0i64;
  this->mActionRequests.mBits[2] = 0i64;
  this->mActionRequests.mBits[3] = 0i64;
  this->mActionRequests.mBits[4] = 0i64;
  this->mActionRequests.mBits[5] = 0i64;
  this->mActionRequests.mBits[6] = 0i64;
  this->mActionRequests.mBits[7] = 0i64;
  this->mActionRequests.mBits[8] = 0i64;
}

// File Line: 296
// RVA: 0x5AF130
void __fastcall UFG::DialogueAnimationComponent::Update(UFG::DialogueAnimationComponent *this, float delta_sec)
{
  UFG::DialogueAnimationComponent *v2; // rbx
  unsigned int v3; // edi
  AnimationDataBase *v4; // rax
  UFG::qBaseTreeRB *v5; // rax
  signed __int64 v6; // rax
  __int64 v7; // rax
  char v8; // al
  UFG::SimObjectCVBase *v9; // rcx
  UFG::AICharacterControllerBaseComponent *v10; // rcx
  unsigned __int16 v11; // dx
  UFG::AICharacterControllerBaseComponent *v12; // rax
  unsigned int v13; // edx
  bool v14; // zf
  UFG::qWiseSymbol result; // [rsp+48h] [rbp+10h]

  v2 = this;
  if ( !(~*((_BYTE *)this + 168) & 1) )
  {
    v3 = this->m_sampleNameHash;
    if ( v3 )
    {
      v4 = AnimationDataBase::GetInstance();
      if ( v3 )
      {
        v5 = UFG::qBaseTreeRB::Get(&v4->mAnimations.mTree, v3);
        if ( v5 )
        {
          v6 = (signed __int64)&v5[-1].mNULL;
          if ( v6 )
          {
            v7 = *(_QWORD *)(v6 + 104);
            if ( v7 )
            {
              if ( *(_QWORD *)(v7 + 96) )
              {
                v2->m_animName.mUID = UFG::qSymbol::qSymbol(&result, v2->m_sampleNameHash)->mUID;
                v8 = *((_BYTE *)v2 + 168) & 0xFE;
                v2->m_currentTime = 0.0;
                v2->m_lastTime = 0.0;
                v2->m_parametricMode = 0;
                v2->m_sampleNameHash = 0;
                *((_BYTE *)v2 + 168) = v8 | 4;
                UFG::DialogueAnimationComponent::PlayFacialAnim(v2, 0);
              }
            }
          }
        }
      }
    }
  }
  v2->m_currentTime = delta_sec + v2->m_currentTime;
  UFG::DialogueAnimationComponent::UpdateAnim(v2, delta_sec);
  v9 = (UFG::SimObjectCVBase *)v2->m_pSimObject;
  if ( v9 )
  {
    v11 = v9->m_Flags;
    if ( (v11 >> 14) & 1 || (v11 & 0x8000u) != 0 )
    {
      v12 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v9);
    }
    else
    {
      if ( (v11 >> 13) & 1 )
      {
        v13 = UFG::AICharacterControllerBaseComponent::_TypeUID;
      }
      else
      {
        v14 = ((v11 >> 12) & 1) == 0;
        v13 = UFG::AICharacterControllerBaseComponent::_TypeUID;
        if ( v14 )
        {
          v12 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                             (UFG::SimObject *)&v9->vfptr,
                                                             UFG::AICharacterControllerBaseComponent::_TypeUID);
          goto LABEL_19;
        }
      }
      v12 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                         (UFG::SimObjectGame *)&v9->vfptr,
                                                         v13);
    }
LABEL_19:
    v10 = v12;
    goto LABEL_20;
  }
  v10 = 0i64;
LABEL_20:
  v10->m_Intention.mActionRequests.mBits[0] |= v2->mActionRequests.mBits[0];
  v10->m_Intention.mActionRequests.mBits[1] |= v2->mActionRequests.mBits[1];
  v10->m_Intention.mActionRequests.mBits[2] |= v2->mActionRequests.mBits[2];
  v10->m_Intention.mActionRequests.mBits[3] |= v2->mActionRequests.mBits[3];
  v10->m_Intention.mActionRequests.mBits[4] |= v2->mActionRequests.mBits[4];
  v10->m_Intention.mActionRequests.mBits[5] |= v2->mActionRequests.mBits[5];
  v10->m_Intention.mActionRequests.mBits[6] |= v2->mActionRequests.mBits[6];
  v10->m_Intention.mActionRequests.mBits[7] |= v2->mActionRequests.mBits[7];
  v10->m_Intention.mActionRequests.mBits[8] |= v2->mActionRequests.mBits[8];
  v10->m_Intention.mSignals = v10->m_Intention.mActionRequests.mBits[0] | v10->m_Intention.mActionRequests.mBits[1] | v10->m_Intention.mActionRequests.mBits[2] | v10->m_Intention.mActionRequests.mBits[3] | v10->m_Intention.mActionRequests.mBits[4] | v10->m_Intention.mActionRequests.mBits[5] | v10->m_Intention.mActionRequests.mBits[6] | v10->m_Intention.mActionRequests.mBits[7] | v10->m_Intention.mActionRequests.mBits[8];
  v2->mActionRequests.mBits[0] = 0i64;
  v2->mActionRequests.mBits[1] = 0i64;
  v2->mActionRequests.mBits[2] = 0i64;
  v2->mActionRequests.mBits[3] = 0i64;
  v2->mActionRequests.mBits[4] = 0i64;
  v2->mActionRequests.mBits[5] = 0i64;
  v2->mActionRequests.mBits[6] = 0i64;
  v2->mActionRequests.mBits[7] = 0i64;
  v2->mActionRequests.mBits[8] = 0i64;
  v2->m_lastTime = v2->m_currentTime;
}

// File Line: 344
// RVA: 0x5AFEA0
char __fastcall UFG::DialogueAnimationComponent::UpdateAnim(UFG::DialogueAnimationComponent *this, float delta_sec)
{
  UFG::DialogueAnimationComponent *v2; // rdi
  AnimationNode *v3; // rcx
  AnimationNode *v4; // rax
  UFG::ActorAudioComponent *v5; // rbx
  UFG::SimObjectCharacter *v6; // rcx
  UFG::ActorAudioComponent *v7; // rax
  unsigned __int16 v8; // dx
  UFG::AudioEvent *v9; // rcx
  AnimationNode *v10; // rax
  float v11; // xmm0_4
  float v12; // xmm1_4
  char v13; // si
  UFG::SimObjectCharacter *v14; // rcx
  unsigned __int16 v15; // dx
  UFG::ActorAudioComponent *v16; // rax
  unsigned int v17; // edx
  bool v18; // zf
  float v19; // xmm1_4
  float v20; // xmm2_4
  Render::DebugDrawContext *v21; // rbx
  char *v22; // rax
  UFG::qVector3 world_position; // [rsp+30h] [rbp-28h]
  float result; // [rsp+60h] [rbp+8h]

  v2 = this;
  v3 = this->m_controller.m_pPointer;
  if ( v3 )
  {
    AnimationNode::verifyBindAnimation(v3);
    v4 = v2->m_controller.m_pPointer;
    v5 = 0i64;
    if ( !v4 || !v4->mSkeletalAnimationHandle.m_SkeletalAnimation.m_pPointer )
      goto LABEL_25;
    v6 = (UFG::SimObjectCharacter *)v2->m_pSimObject;
    if ( v6 )
    {
      v8 = v6->m_Flags;
      if ( (v8 >> 14) & 1 )
      {
        v7 = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(v6);
      }
      else if ( (v8 & 0x8000u) == 0 )
      {
        if ( (v8 >> 13) & 1 )
        {
          v7 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                             (UFG::SimObjectGame *)&v6->vfptr,
                                             UFG::ActorAudioComponent::_TypeUID);
        }
        else if ( (v8 >> 12) & 1 )
        {
          v7 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                             (UFG::SimObjectGame *)&v6->vfptr,
                                             UFG::ActorAudioComponent::_TypeUID);
        }
        else
        {
          v7 = (UFG::ActorAudioComponent *)UFG::SimObject::GetComponentOfType(
                                             (UFG::SimObject *)&v6->vfptr,
                                             UFG::ActorAudioComponent::_TypeUID);
        }
      }
      else
      {
        v7 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                           (UFG::SimObjectGame *)&v6->vfptr,
                                           UFG::ActorAudioComponent::_TypeUID);
      }
    }
    else
    {
      v7 = 0i64;
    }
    v9 = v7->m_controller.m_pEvent;
    if ( UFG::DialogueAnimationComponent::sm_correctTimes )
    {
      result = 0.0;
      if ( !v9 || !UFG::AudioEvent::GetElapsedTime(v9, &result, 1) )
        goto LABEL_23;
      v10 = v2->m_controller.m_pPointer;
      result = result * 0.001;
      v11 = SkeletalAnimation::GetDuration(v10->mSkeletalAnimationHandle.m_SkeletalAnimation.m_pPointer);
      v12 = (float)((float)(result / v2->m_sampleDuration) * v11) + UFG::DialogueAnimationComponent::sm_animOffset;
    }
    else
    {
      if ( !v9 || !UFG::AudioEvent::GetElapsedTime(v9, &result, 1) )
        goto LABEL_23;
      result = result * 0.001;
    }
    ((void (*)(void))v2->m_controller.m_pPointer->vfptr[3].GetResourcePath)();
LABEL_23:
    if ( !((unsigned __int8 (*)(void))v2->m_controller.m_pPointer->vfptr[1].SetResourceOwner)() )
    {
      v13 = 1;
LABEL_26:
      if ( !UFG::DialogueAnimationComponent::sm_debugFace )
        return v13;
      v14 = (UFG::SimObjectCharacter *)v2->m_pSimObject;
      if ( !v14 )
      {
LABEL_38:
        v19 = v5->m_WorldMatrix.v3.y;
        v20 = v5->m_WorldMatrix.v3.z + 1.3;
        world_position.x = v5->m_WorldMatrix.v3.x;
        world_position.y = v19;
        world_position.z = v20;
        v21 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 3u);
        v22 = UFG::qSymbol::as_cstr_dbg(&v2->m_animName);
        Render::DebugDrawContext::DrawText(
          v21,
          &world_position,
          &UFG::qColour::Red,
          "Playing: %2.2f  %s",
          v2->m_currentTime,
          v22,
          *(_QWORD *)&world_position.x,
          *(_QWORD *)&world_position.z);
        return v13;
      }
      v15 = v14->m_Flags;
      if ( (v15 >> 14) & 1 )
      {
        v16 = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(v14);
      }
      else
      {
        if ( (v15 & 0x8000u) != 0 || (v15 >> 13) & 1 )
        {
          v17 = UFG::ActorAudioComponent::_TypeUID;
        }
        else
        {
          v18 = ((v15 >> 12) & 1) == 0;
          v17 = UFG::ActorAudioComponent::_TypeUID;
          if ( v18 )
          {
            v16 = (UFG::ActorAudioComponent *)UFG::SimObject::GetComponentOfType(
                                                (UFG::SimObject *)&v14->vfptr,
                                                UFG::ActorAudioComponent::_TypeUID);
            goto LABEL_37;
          }
        }
        v16 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                            (UFG::SimObjectGame *)&v14->vfptr,
                                            v17);
      }
LABEL_37:
      v5 = v16;
      goto LABEL_38;
    }
    ((void (*)(void))v2->m_controller.m_pPointer->vfptr[1].GetResourceOwner)();
LABEL_25:
    v13 = 0;
    goto LABEL_26;
  }
  return 0;
}

// File Line: 415
// RVA: 0x59B650
void __fastcall UFG::DialogueAnimationComponent::EndFacialAnim(UFG::DialogueAnimationComponent *this)
{
  UFG::DialogueAnimationComponent *v1; // rbx
  char *v2; // rax
  PoseNode *v3; // rax

  v1 = this;
  if ( this->m_controller.m_pPointer )
  {
    if ( this->m_splitBodyBlend.m_pPointer )
    {
      if ( UFG::DialogueAnimationComponent::sm_debugFace )
      {
        v2 = UFG::qSymbol::as_cstr_dbg(&this->m_animName);
        UFG::qPrintf("Fac Anim Trc: Ending : %s\n", v2);
      }
      v3 = v1->m_splitBodyBlend.m_pPointer;
      if ( UFG::DialogueAnimationComponent::sm_blendOut == 0.0 )
      {
        HIDWORD(v3[1].mParent.mOffset) = -1082130432;
        v3[1].mPriority = 0;
LABEL_9:
        BYTE3(v3[1].mParent.mOffset) = 0;
        goto LABEL_10;
      }
      if ( UFG::DialogueAnimationComponent::sm_blendOut > 0.0 )
      {
        *((float *)&v3[1].mParent.mOffset + 1) = -1.0 / UFG::DialogueAnimationComponent::sm_blendOut;
        goto LABEL_9;
      }
    }
LABEL_10:
    v1->m_animName = UFG::gNullQSymbolUC;
  }
}

// File Line: 480
// RVA: 0x155D120
__int64 UFG::_dynamic_initializer_for__symFaceInGame__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("FaceInGame", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symFaceInGame, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__symFaceInGame__);
}

// File Line: 483
// RVA: 0x5A5990
void __fastcall UFG::DialogueAnimationComponent::PlayFacialAnim(UFG::DialogueAnimationComponent *this, AnimationPlayMode mode)
{
  AnimationPlayMode v2; // er12
  UFG::DialogueAnimationComponent *v3; // rdi
  char *v4; // rax
  UFG::SimObjectCVBase *v5; // rcx
  AnimationNode *v6; // rsi
  UFG::CharacterAnimationComponent *v7; // rax
  unsigned __int16 v8; // dx
  Creature *v9; // r15
  char *v10; // rax
  PoseNodeParent *v11; // rax
  PoseNodeParent *v12; // rbp
  UFG::qSafePointer<PoseNode,PoseNode> *v13; // r8
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *v14; // rcx
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *v15; // rax
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *v16; // rax
  PoseNode *v17; // rbx
  char *v18; // rax
  AnimationNode *v19; // rax
  UFG::qSafePointer<AnimationNode,AnimationNode> *v20; // rdx
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v21; // rcx
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v22; // rax
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v23; // rax
  UFG::SimObjectCharacter *v24; // rcx
  unsigned __int16 v25; // dx
  unsigned int v26; // edx
  bool v27; // zf
  int returnCode; // [rsp+B0h] [rbp+18h]
  char *v29; // [rsp+B8h] [rbp+20h]

  v2 = mode;
  v3 = this;
  if ( UFG::DialogueAnimationComponent::SetFacialActionContext(this) && v3->m_animName.mUID != UFG::gNullQSymbolUC.mUID )
  {
    if ( UFG::DialogueAnimationComponent::sm_debugFace )
    {
      v4 = UFG::qSymbol::as_cstr_dbg(&v3->m_animName);
      UFG::qPrintf("Fac Anim Trc: Playing : %s\n", v4);
    }
    v5 = (UFG::SimObjectCVBase *)v3->mFacialContext->mSimObject.m_pPointer;
    v6 = 0i64;
    if ( v5 )
    {
      v8 = v5->m_Flags;
      if ( (v8 >> 14) & 1 )
      {
        v7 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v5);
      }
      else if ( (v8 & 0x8000u) == 0 )
      {
        if ( (v8 >> 13) & 1 )
          v7 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v5);
        else
          v7 = (UFG::CharacterAnimationComponent *)((v8 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                       (UFG::SimObjectGame *)&v5->vfptr,
                                                                       UFG::CharacterAnimationComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v5->vfptr, UFG::CharacterAnimationComponent::_TypeUID));
      }
      else
      {
        v7 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v5);
      }
    }
    else
    {
      v7 = 0i64;
    }
    v9 = v7->mCreature;
    if ( v9 )
    {
      v10 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0xB0ui64, "BlendAddNode", 0i64, 1u);
      v29 = v10;
      if ( v10 )
      {
        BlendAddNode::BlendAddNode((BlendAddNode *)v10, UFG::DialogueAnimationComponent::sm_blendIn);
        v12 = v11;
      }
      else
      {
        v12 = 0i64;
      }
      v13 = &v3->m_splitBodyBlend;
      if ( v3->m_splitBodyBlend.m_pPointer )
      {
        v14 = v13->mPrev;
        v15 = v3->m_splitBodyBlend.mNext;
        v14->mNext = v15;
        v15->mPrev = v14;
        v13->mPrev = (UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *)&v13->mPrev;
        v3->m_splitBodyBlend.mNext = (UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *)&v3->m_splitBodyBlend.mPrev;
      }
      v3->m_splitBodyBlend.m_pPointer = (PoseNode *)&v12->vfptr;
      if ( v12 )
      {
        v16 = v12->m_SafePointerList.mNode.mPrev;
        v16->mNext = (UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *)&v13->mPrev;
        v13->mPrev = v16;
        v3->m_splitBodyBlend.mNext = &v12->m_SafePointerList.mNode;
        v12->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *)&v13->mPrev;
      }
      v17 = v3->m_splitBodyBlend.m_pPointer;
      v17[1].mPrev = (UFG::qNode<PoseNode,PoseNode> *)Creature::GetWeightSet(
                                                        v9,
                                                        (UFG::qSymbolUC *)&UFG::symFaceInGame.mUID);
      v18 = UFG::qMemoryPool2::Allocate(
              &gActionTreeMemoryPool,
              0x170ui64,
              "DialogueAnimationComponent.AnimationNode",
              0i64,
              1u);
      v29 = v18;
      if ( v18 )
      {
        AnimationNode::AnimationNode((AnimationNode *)v18, &v3->m_animName, v2, 0.0, -1.0);
        v6 = v19;
      }
      v20 = &v3->m_controller;
      if ( v3->m_controller.m_pPointer )
      {
        v21 = v20->mPrev;
        v22 = v3->m_controller.mNext;
        v21->mNext = v22;
        v22->mPrev = v21;
        v20->mPrev = (UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *)&v20->mPrev;
        v3->m_controller.mNext = (UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *)&v3->m_controller.mPrev;
      }
      v3->m_controller.m_pPointer = v6;
      if ( v6 )
      {
        v23 = v6->m_SafePointerList.mNode.mPrev;
        v23->mNext = (UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *)&v20->mPrev;
        v20->mPrev = v23;
        v3->m_controller.mNext = &v6->m_SafePointerList.mNode;
        v6->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *)&v20->mPrev;
      }
      ((void (*)(void))v3->m_controller.m_pPointer->vfptr[3].ResolveReferences)();
      v24 = (UFG::SimObjectCharacter *)v3->m_pSimObject;
      if ( !v24 )
        goto LABEL_39;
      v25 = v24->m_Flags;
      if ( (v25 >> 14) & 1 )
      {
        UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(v24);
      }
      else
      {
        if ( (v25 & 0x8000u) != 0 || (v25 >> 13) & 1 )
        {
          v26 = UFG::ActorAudioComponent::_TypeUID;
        }
        else
        {
          v27 = ((v25 >> 12) & 1) == 0;
          v26 = UFG::ActorAudioComponent::_TypeUID;
          if ( v27 )
          {
            UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v24->vfptr, UFG::ActorAudioComponent::_TypeUID);
            goto LABEL_39;
          }
        }
        UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v24->vfptr, v26);
      }
LABEL_39:
      Creature::PlayBlendTree(v9, (PoseNode *)&v3->m_controller.m_pPointer->vfptr, v12, 10, 0, 0.0, -1.0, &returnCode);
      ((void (__fastcall *)(AnimationNode *, ActionContext *))v3->m_controller.m_pPointer->vfptr[2].GetResourceOwner)(
        v3->m_controller.m_pPointer,
        v3->mFacialContext);
      return;
    }
  }
}

// File Line: 513
// RVA: 0x5AC870
void __fastcall UFG::DialogueAnimationComponent::Stop(UFG::DialogueAnimationComponent *this)
{
  UFG::DialogueAnimationComponent *v1; // rbx
  UFG::qSymbolUC *v2; // rcx
  char *v3; // rax

  v1 = this;
  if ( UFG::DialogueAnimationComponent::sm_debugFace )
  {
    v2 = &this->m_animName;
    if ( v2->mUID != -1 )
    {
      v3 = UFG::qSymbol::as_cstr_dbg(v2);
      UFG::qPrintf("Fac Anim Trc: Stop : %s\n", v3);
    }
  }
  UFG::DialogueAnimationComponent::EndFacialAnim(v1);
  *((_BYTE *)v1 + 168) = *((_BYTE *)v1 + 168) & 0xFB | 1;
  v1->m_currentTime = 0.0;
  v1->m_lastTime = 0.0;
  v1->m_parametricMode = 0;
  *(_QWORD *)&v1->m_sampleNameHash = 0i64;
  v1->m_animName = UFG::gNullQSymbolUC;
}

// File Line: 551
// RVA: 0x5AAE60
char __fastcall UFG::DialogueAnimationComponent::SetFacialActionContext(UFG::DialogueAnimationComponent *this)
{
  UFG::DialogueAnimationComponent *v1; // rbx
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::SimComponent *v4; // rax

  v1 = this;
  v2 = (UFG::SimObjectGame *)this->m_pSimObject;
  if ( !v2 )
    goto LABEL_11;
  v3 = v2->m_Flags;
  if ( (v3 >> 14) & 1 )
  {
    v4 = v2->m_Components.p[31].m_pComponent;
  }
  else
  {
    if ( (v3 & 0x8000u) != 0 || (v3 >> 13) & 1 )
      goto LABEL_11;
    if ( (v3 >> 12) & 1 )
      v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::FacialActionTreeComponent::_TypeUID);
    else
      v4 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::FacialActionTreeComponent::_TypeUID);
  }
  if ( v4 )
  {
    v1->mFacialContext = (ActionContext *)v4[3].vfptr;
    return 1;
  }
LABEL_11:
  v1->mFacialContext = 0i64;
  return 0;
}

