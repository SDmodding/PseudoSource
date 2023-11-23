// File Line: 100
// RVA: 0x66AE60
void __fastcall UFG::VehicleEffect::VehicleEffect(UFG::VehicleEffect *this, const char *name)
{
  unsigned int v4; // eax
  Render::FXOverride *m_pPointer; // rax
  Render::FXOverride *v6; // rbx

  v4 = UFG::qStringHashUpper32(name, -1);
  this->mNode.mParent = 0i64;
  this->mNode.mChild[0] = 0i64;
  this->mNode.mChild[1] = 0i64;
  this->mNode.mUID = v4;
  UFG::qSymbol::create_from_string(&this->mName, name);
  this->mTransform.mUID = -1;
  this->mMarkerHash.mUID = -1;
  this->mDamageAffectorHash.mUID = -1;
  this->mDamageBoneHash.mUID = -1;
  this->mEffectOverride.m_pPointer = 0i64;
  UFG::qSymbol::set_null(&this->mTransform);
  this->mMarker = -1;
  this->mMarkerHash = UFG::gNullQSymbolUC;
  this->mDamageBone = -1;
  this->mDamageBoneHash = UFG::gNullQSymbolUC;
  this->mDamageAffectorBone = -1;
  this->mDamageAffectorHash = UFG::gNullQSymbolUC;
  *(_QWORD *)&this->mForwardBone = -1i64;
  this->mEffectRef = -1;
  m_pPointer = this->mEffectOverride.m_pPointer;
  if ( m_pPointer )
  {
    --m_pPointer->mReferenceCount;
    v6 = this->mEffectOverride.m_pPointer;
    if ( v6->mReferenceCount <= 0 )
    {
      if ( v6 )
      {
        Render::FXOverride::~FXOverride(this->mEffectOverride.m_pPointer);
        operator delete[](v6);
      }
      this->mEffectOverride.m_pPointer = 0i64;
    }
    this->mEffectOverride.m_pPointer = 0i64;
  }
  this->mDamageMarkerIndex = -1;
  *(_QWORD *)&this->mRequestedSpeed = 0i64;
  *(_QWORD *)this->mBoundEffect = -1i64;
  *(_QWORD *)&this->mBoundEffect[2] = -1i64;
}

// File Line: 126
// RVA: 0x66AD50
void __fastcall UFG::VehicleEffect::VehicleEffect(UFG::VehicleEffect *this, UFG::VehicleEffect *effect)
{
  unsigned int mUID; // eax
  Render::FXOverride *m_pPointer; // rax
  Render::FXOverride *v6; // rsi

  mUID = effect->mName.mUID;
  this->mNode.mParent = 0i64;
  this->mNode.mChild[0] = 0i64;
  this->mNode.mChild[1] = 0i64;
  this->mNode.mUID = mUID;
  this->mName.mUID = effect->mName.mUID;
  this->mTransform.mUID = -1;
  this->mMarkerHash.mUID = -1;
  this->mDamageAffectorHash.mUID = -1;
  this->mDamageBoneHash.mUID = -1;
  this->mEffectOverride.m_pPointer = 0i64;
  this->mTransform.mUID = effect->mTransform.mUID;
  this->mMarker = effect->mMarker;
  this->mMarkerHash.mUID = effect->mMarkerHash.mUID;
  this->mDamageBone = effect->mDamageBone;
  this->mDamageBoneHash.mUID = effect->mDamageBoneHash.mUID;
  this->mDamageAffectorBone = effect->mDamageAffectorBone;
  this->mDamageAffectorHash.mUID = effect->mDamageAffectorHash.mUID;
  this->mForwardBone = effect->mForwardBone;
  this->mRearBone = effect->mRearBone;
  this->mEffectRef = -1;
  m_pPointer = this->mEffectOverride.m_pPointer;
  if ( m_pPointer )
  {
    --m_pPointer->mReferenceCount;
    v6 = this->mEffectOverride.m_pPointer;
    if ( v6->mReferenceCount <= 0 )
    {
      if ( v6 )
      {
        Render::FXOverride::~FXOverride(this->mEffectOverride.m_pPointer);
        operator delete[](v6);
      }
      this->mEffectOverride.m_pPointer = 0i64;
    }
    this->mEffectOverride.m_pPointer = 0i64;
  }
  this->mDamageMarkerIndex = effect->mDamageMarkerIndex;
  *(_QWORD *)&this->mRequestedSpeed = 0i64;
  this->mBoundEffect[0] = effect->mBoundEffect[0];
  this->mBoundEffect[1] = effect->mBoundEffect[1];
  this->mBoundEffect[2] = effect->mBoundEffect[2];
  this->mBoundEffect[3] = effect->mBoundEffect[3];
}

// File Line: 150
// RVA: 0x66DC60
UFG::VehicleEffect *__fastcall UFG::VehicleEffect::operator=(UFG::VehicleEffect *this, UFG::VehicleEffect *rhs)
{
  unsigned int mRearBone; // eax
  Render::FXOverride *m_pPointer; // rax
  Render::FXOverride *v6; // rsi

  if ( this != rhs )
  {
    this->mTransform.mUID = rhs->mTransform.mUID;
    this->mMarker = rhs->mMarker;
    this->mMarkerHash.mUID = rhs->mMarkerHash.mUID;
    this->mDamageBone = rhs->mDamageBone;
    this->mDamageBoneHash.mUID = rhs->mDamageBoneHash.mUID;
    this->mDamageAffectorBone = rhs->mDamageAffectorBone;
    this->mDamageAffectorHash.mUID = rhs->mDamageAffectorHash.mUID;
    this->mForwardBone = rhs->mForwardBone;
    mRearBone = rhs->mRearBone;
    this->mEffectRef = -1;
    this->mRearBone = mRearBone;
    m_pPointer = this->mEffectOverride.m_pPointer;
    if ( m_pPointer )
    {
      --m_pPointer->mReferenceCount;
      v6 = this->mEffectOverride.m_pPointer;
      if ( v6->mReferenceCount <= 0 )
      {
        if ( v6 )
        {
          Render::FXOverride::~FXOverride(this->mEffectOverride.m_pPointer);
          operator delete[](v6);
        }
        this->mEffectOverride.m_pPointer = 0i64;
      }
      this->mEffectOverride.m_pPointer = 0i64;
    }
    this->mDamageMarkerIndex = rhs->mDamageMarkerIndex;
    this->mBoundEffect[0] = rhs->mBoundEffect[0];
    this->mBoundEffect[1] = rhs->mBoundEffect[1];
    this->mBoundEffect[2] = rhs->mBoundEffect[2];
    this->mBoundEffect[3] = rhs->mBoundEffect[3];
  }
  return this;
}

// File Line: 208
// RVA: 0x66AF70
void __fastcall UFG::VehicleEffectState::VehicleEffectState(UFG::VehicleEffectState *this, unsigned int *symbol)
{
  unsigned int v3; // eax

  v3 = *symbol;
  this->mNode.mParent = 0i64;
  this->mNode.mChild[0] = 0i64;
  this->mNode.mChild[1] = 0i64;
  this->mNode.mUID = v3;
  this->mStateSymbol.mUID = *symbol;
  UFG::qBaseTreeRB::qBaseTreeRB(&this->mEffects.mTree);
  this->mPhantom = 0i64;
}

