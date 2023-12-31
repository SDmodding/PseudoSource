// File Line: 12
// RVA: 0x66ABB0
void __fastcall UFG::VehicleCombatStats::VehicleCombatStats(UFG::VehicleCombatStats *this)
{
  __int64 v2; // rdx

  v2 = 7i64;
  do
  {
    this->mLastAttack[0] = 0.0;
    this->mNumAttacks[0] = 0;
    this = (UFG::VehicleCombatStats *)((char *)this + 4);
    --v2;
  }
  while ( v2 );
}

// File Line: 17
// RVA: 0x689A20
void __fastcall UFG::VehicleCombatStats::Reset(UFG::VehicleCombatStats *this)
{
  __int64 v1; // rax

  v1 = 7i64;
  do
  {
    this->mLastAttack[0] = 0.0;
    this->mNumAttacks[0] = 0;
    this = (UFG::VehicleCombatStats *)((char *)this + 4);
    --v1;
  }
  while ( v1 );
}

// File Line: 26
// RVA: 0x68D290
void __fastcall UFG::VehicleCombatStats::Tick(UFG::VehicleCombatStats *this, float seconds)
{
  float v3; // xmm2_4
  float v4; // xmm0_4
  float v5; // xmm1_4
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm3_4

  v3 = seconds + this->mLastAttack[1];
  this->mLastAttack[0] = seconds + this->mLastAttack[0];
  this->mLastAttack[1] = v3;
  v4 = seconds + this->mLastAttack[2];
  v5 = seconds + this->mLastAttack[3];
  this->mLastAttack[2] = v4;
  this->mLastAttack[3] = v5;
  v6 = seconds + this->mLastAttack[4];
  v7 = seconds + this->mLastAttack[5];
  v8 = seconds + this->mLastAttack[6];
  this->mLastAttack[4] = v6;
  this->mLastAttack[5] = v7;
  this->mLastAttack[6] = v8;
}

// File Line: 34
// RVA: 0x670980
void __fastcall UFG::VehicleCombatStats::AttackOccured(UFG::VehicleCombatStats *this, unsigned int attack)
{
  if ( attack <= 3 )
  {
    ++this->mNumAttacks[4];
    this->mLastAttack[4] = 0.0;
  }
  ++this->mNumAttacks[attack];
  this->mLastAttack[attack] = 0.0;
  ++this->mNumAttacks[6];
  this->mLastAttack[6] = 0.0;
}

