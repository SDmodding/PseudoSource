// File Line: 80
// RVA: 0x3FDDB0
void __fastcall UFG::WorldEffectsManager::UIElement::UIElement(UFG::WorldEffectsManager::UIElement *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::CharacterEffectsComponent> *v1; // [rsp+48h] [rbp+10h]

  this->mHealthFXOverride.m_pPointer = 0i64;
  this->mFightClassFXOverride.m_pPointer = 0i64;
  v1 = &this->mComponent;
  v1->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mPrev;
  v1->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mPrev;
  this->mComponent.m_pPointer = 0i64;
  this->mTransformNode = 0i64;
  UFG::WorldEffectsManager::UIElement::Reset(this);
}

// File Line: 85
// RVA: 0x4010F0
void __fastcall UFG::WorldEffectsManager::UIElement::Reset(UFG::WorldEffectsManager::UIElement *this)
{
  Render::FXOverride *v1; // rax
  UFG::WorldEffectsManager::UIElement *v2; // rbx
  Render::FXOverride *v3; // rdi
  Render::FXOverride *v4; // rax
  Render::FXOverride *v5; // rdi
  float v6; // xmm2_4
  float v7; // xmm0_4
  UFG::qSafePointer<UFG::SimComponent,UFG::CharacterEffectsComponent> *v8; // rbx
  float v9; // xmm2_4
  float v10; // xmm0_4
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rax

  this->mIsAlly = 0;
  *(_QWORD *)&this->mHealthUIType = 0i64;
  this->mCurrentHealthUI = 0;
  v1 = this->mHealthFXOverride.m_pPointer;
  v2 = this;
  if ( v1 )
  {
    --v1->mReferenceCount;
    v3 = this->mHealthFXOverride.m_pPointer;
    if ( v3->mReferenceCount <= 0 )
    {
      if ( v3 )
      {
        Render::FXOverride::~FXOverride(this->mHealthFXOverride.m_pPointer);
        operator delete[](v3);
      }
      v2->mHealthFXOverride.m_pPointer = 0i64;
    }
    v2->mHealthFXOverride.m_pPointer = 0i64;
  }
  v2->mHealthUIID = 0;
  v4 = v2->mFightClassFXOverride.m_pPointer;
  if ( v4 )
  {
    --v4->mReferenceCount;
    v5 = v2->mFightClassFXOverride.m_pPointer;
    if ( v5->mReferenceCount <= 0 )
    {
      if ( v5 )
      {
        Render::FXOverride::~FXOverride(v2->mFightClassFXOverride.m_pPointer);
        operator delete[](v5);
      }
      v2->mFightClassFXOverride.m_pPointer = 0i64;
    }
    v2->mFightClassFXOverride.m_pPointer = 0i64;
  }
  v2->mFightClassUIID = 0;
  v6 = UFG::qVector3::msZero.z;
  v7 = UFG::qVector3::msZero.x;
  v2->mCurrentNormal.y = UFG::qVector3::msZero.y;
  v8 = &v2->mComponent;
  *((float *)&v8[-2].m_pPointer + 1) = v7;
  *((float *)&v8[-1].mPrev + 1) = v6;
  v9 = UFG::qVector3::msZero.z;
  v10 = UFG::qVector3::msZero.x;
  HIDWORD(v8[-1].mNext) = LODWORD(UFG::qVector3::msZero.y);
  *(float *)&v8[-1].mNext = v10;
  *(float *)&v8[-1].m_pPointer = v9;
  if ( v8->m_pPointer )
  {
    v11 = v8->mPrev;
    v12 = v8->mNext;
    v11->mNext = v12;
    v12->mPrev = v11;
    v8->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
    v8->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
  }
  v8->m_pPointer = 0i64;
}

