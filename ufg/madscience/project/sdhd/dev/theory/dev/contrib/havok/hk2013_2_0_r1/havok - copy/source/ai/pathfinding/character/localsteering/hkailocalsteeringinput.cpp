// File Line: 16
// RVA: 0xBD4C00
void __fastcall hkaiLocalSteeringInput::init(hkaiLocalSteeringInput *this, hkaiCharacter *character)
{
  this->m_character = character;
  *(_QWORD *)&this->m_distToLocalGoal = 0i64;
  this->m_referenceFrame = 0i64;
  this->m_currentPosition = 0i64;
  this->m_currentForward = 0i64;
  this->m_currentUp = 0i64;
  this->m_currentVelocity = 0i64;
  this->m_desiredVelocity = 0i64;
  this->m_desiredFutureDir = 0i64;
  this->m_localGoalPlane = 0i64;
  this->m_avoidanceProperties = character->m_avoidanceProperties.m_pntr;
  *(_DWORD *)&this->m_isLocalGoalLast.m_bool = 0x1000000;
}

// File Line: 42
// RVA: 0xBD4C50
void __fastcall hkaiLocalSteeringInput::init(hkaiLocalSteeringInput *this, hkaiCharacter *character, hkaiReferenceFrame *referenceFrame, hkaiPathFollowingCharacterState *characterState)
{
  hkaiPathFollowingCharacterState *v4; // rdi
  hkaiReferenceFrame *v5; // rsi
  hkaiLocalSteeringInput *v6; // rbx
  hkVector4f v7; // xmm1

  v4 = characterState;
  v5 = referenceFrame;
  v6 = this;
  hkaiLocalSteeringInput::init(this, character);
  v6->m_currentPosition = v4->m_position;
  v6->m_currentForward = v4->m_forward;
  v6->m_currentUp = v4->m_up;
  v7.m_quad = (__m128)v4->m_velocity;
  v6->m_referenceFrame = v5;
  v6->m_currentVelocity = (hkVector4f)v7.m_quad;
}

