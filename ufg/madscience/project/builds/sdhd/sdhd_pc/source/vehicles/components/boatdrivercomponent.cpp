// File Line: 23
// RVA: 0x157B750
__int64 dynamic_initializer_for__UFG::BoatHumanDriverComponent::s_BoatHumanDriverComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::BoatHumanDriverComponent::s_BoatHumanDriverComponentList__);
}

// File Line: 24
// RVA: 0x67B4E0
signed __int64 __fastcall UFG::qReflectInventory<UFG::Editor::SceneLayerPropertiesWindow>::GetClassSize(UFG::qReflectInventory<UFG::Editor::SceneLayerPropertiesWindow> *this)
{
  return 416i64;
}

// File Line: 30
// RVA: 0x666F30
void __fastcall UFG::BoatHumanDriverComponent::BoatHumanDriverComponent(UFG::BoatHumanDriverComponent *this, unsigned int name_uid)
{
  UFG::BoatHumanDriverComponent *v2; // rbx
  UFG::qNode<UFG::BoatHumanDriverComponent,UFG::BoatHumanDriverComponent> *v3; // rdx
  UFG::qNode<UFG::BoatHumanDriverComponent,UFG::BoatHumanDriverComponent> *v4; // rax

  v2 = this;
  UFG::HumanDriverComponent::HumanDriverComponent((UFG::HumanDriverComponent *)&this->vfptr, name_uid);
  v3 = (UFG::qNode<UFG::BoatHumanDriverComponent,UFG::BoatHumanDriverComponent> *)&v2->mPrev;
  v3->mPrev = v3;
  v3->mNext = v3;
  v2->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::BoatHumanDriverComponent::`vftable{for `UFG::SimComponent};
  v2->vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::BoatHumanDriverComponent::`vftable{for `UFG::UpdateInterface};
  v4 = UFG::BoatHumanDriverComponent::s_BoatHumanDriverComponentList.mNode.mPrev;
  UFG::BoatHumanDriverComponent::s_BoatHumanDriverComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::BoatHumanDriverComponent,UFG::BoatHumanDriverComponent> *)&v2->mPrev;
  v3->mPrev = v4;
  v2->mNext = (UFG::qNode<UFG::BoatHumanDriverComponent,UFG::BoatHumanDriverComponent> *)&UFG::BoatHumanDriverComponent::s_BoatHumanDriverComponentList;
  UFG::BoatHumanDriverComponent::s_BoatHumanDriverComponentList.mNode.mPrev = (UFG::qNode<UFG::BoatHumanDriverComponent,UFG::BoatHumanDriverComponent> *)&v2->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v2->vfptr,
    UFG::BoatHumanDriverComponent::_BoatHumanDriverComponentTypeUID,
    "BoatHumanDriverComponent");
}

// File Line: 38
// RVA: 0x66C170
void __fastcall UFG::BoatHumanDriverComponent::~BoatHumanDriverComponent(UFG::BoatHumanDriverComponent *this)
{
  UFG::BoatHumanDriverComponent *v1; // r8
  UFG::qNode<UFG::BoatHumanDriverComponent,UFG::BoatHumanDriverComponent> *v2; // rdx
  UFG::qNode<UFG::BoatHumanDriverComponent,UFG::BoatHumanDriverComponent> *v3; // rcx
  UFG::qNode<UFG::BoatHumanDriverComponent,UFG::BoatHumanDriverComponent> *v4; // rax
  UFG::qNode<UFG::BoatHumanDriverComponent,UFG::BoatHumanDriverComponent> *v5; // rcx
  UFG::qNode<UFG::BoatHumanDriverComponent,UFG::BoatHumanDriverComponent> *v6; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::BoatHumanDriverComponent::`vftable{for `UFG::SimComponent};
  this->vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::BoatHumanDriverComponent::`vftable{for `UFG::UpdateInterface};
  if ( this == UFG::BoatHumanDriverComponent::s_BoatHumanDriverComponentpCurrentIterator )
    UFG::BoatHumanDriverComponent::s_BoatHumanDriverComponentpCurrentIterator = (UFG::BoatHumanDriverComponent *)&this->mPrev[-25];
  v2 = (UFG::qNode<UFG::BoatHumanDriverComponent,UFG::BoatHumanDriverComponent> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::HumanDriverComponent::~HumanDriverComponent((UFG::HumanDriverComponent *)&v1->vfptr);
}

// File Line: 45
// RVA: 0x68F610
void __fastcall UFG::BoatHumanDriverComponent::Update(UFG::BoatHumanDriverComponent *this, float deltaTime)
{
  UFG::BoatHumanDriverComponent *v2; // rbx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v3; // r8
  UFG::Controller *v4; // rcx
  int v5; // eax
  float v6; // xmm1_4
  __int64 v7; // r9
  int v8; // ecx
  UFG::InputActionData *v9; // rdx
  UFG::InputActionData *v10; // rax
  UFG::InputActionData *v11; // rax
  UFG::InputActionData *v12; // rax
  UFG::InputActionData *v13; // rax
  UFG::InputActionData *v14; // rax
  UFG::InputActionData *v15; // rax
  UFG::InputActionData *v16; // rax
  float v17; // xmm1_4

  v2 = this;
  UFG::HumanDriverComponent::Update((UFG::HumanDriverComponent *)&this->vfptr, deltaTime);
  v3 = v2->m_BoundComponentHandles.mNode.mPrev;
  v4 = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum];
  v5 = (int)v2->mAudioComponent.mNext;
  v6 = *((float *)&v3[43].mPrev + 1) * 3.5999999;
  *(_QWORD *)&v2->mBreakOnUpdate = v4;
  if ( v5 == 1 )
  {
LABEL_4:
    LODWORD(v3[6].mNext) |= 2u;
    return;
  }
  if ( v5 != 2 )
  {
    if ( (unsigned int)(v5 - 4) > 1 )
      return;
    goto LABEL_4;
  }
  if ( v2->mAudioComponent.mPrev )
  {
    v7 = (signed int)v4->mControllerIndex;
    LODWORD(v3[6].mNext) &= 0xFFFFFFEF;
    v8 = (int)v3[6].mNext;
    if ( v6 > 10.0
      && COERCE_FLOAT(LODWORD(v3[5].mNext) & _xmm) > 0.89999998
      && (v9 = UFG::ActionDef_HandBrake.mDataPerController[v7]) != 0i64
      && v9->mActionTrue )
    {
      LODWORD(v3[6].mNext) = v8 | 0x10;
    }
    else if ( COERCE_FLOAT(LODWORD(v6) & _xmm) < 10.0
           && !*(&v2->mHangTime.mIsStarted + 1)
           && ((v10 = UFG::ActionDef_Accelerate.mDataPerController[v7]) != 0i64 && v10->mActionTrue
            || (v11 = UFG::ActionDef_AccelerateButton.mDataPerController[v7]) != 0i64 && v11->mActionTrue)
           && (v12 = UFG::ActionDef_HandBrake.mDataPerController[v7]) != 0i64
           && v12->mActionTrue )
    {
      LODWORD(v3[6].mPrev) = -1082130432;
      HIDWORD(v3[6].mPrev) = -1082130432;
      LODWORD(v3[6].mNext) = v8 & 0xFFFFFFFB | 0x20;
    }
    else
    {
      v13 = UFG::ActionDef_HandBrake.mDataPerController[v7];
      if ( v13 && v13->mActionTrue
        || ((v14 = UFG::ActionDef_Brake.mDataPerController[v7]) != 0i64
         && v14->mActionTrue
         && !BYTE4(v2->m_ChaseSpawnTransform->m_SafePointerList.mNode.mNext)
         || (v15 = UFG::ActionDef_BrakeButton.mDataPerController[v7]) != 0i64 && v15->mActionTrue)
        && (v16 = UFG::ActionDef_Accelerate.mDataPerController[v7]) != 0i64
        && v16->mActionTrue )
      {
        v17 = v6 * 0.1;
        if ( COERCE_FLOAT(LODWORD(v17) & _xmm) > 1.0 )
          v17 = v17 / (float)(COERCE_FLOAT(LODWORD(v17) & _xmm) + 0.00000011920929);
        *(float *)&v3[6].mPrev = v17;
        *((float *)&v3[6].mPrev + 1) = v17;
        LODWORD(v3[6].mNext) = v8 & 0xFFFFFFFE;
      }
    }
  }
}

