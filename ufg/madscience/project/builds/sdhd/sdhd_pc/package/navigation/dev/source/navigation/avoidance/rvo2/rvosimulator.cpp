// File Line: 86
// RVA: 0xF6430
void __fastcall RVO::RVOSimulator::~RVOSimulator(RVO::RVOSimulator *this)
{
  RVO::Agent *defaultAgent; // rbx
  unsigned __int64 v3; // rsi
  RVO::Agent **i; // rcx
  RVO::Agent *v5; // rbx
  RVO::Line *Myfirst; // rcx
  std::pair<float,RVO::Obstacle const *> *v7; // rcx
  RVO::Obstacle **v8; // rcx

  defaultAgent = this->defaultAgent_;
  if ( defaultAgent )
  {
    RVO::Agent::~Agent(this->defaultAgent_);
    operator delete[](defaultAgent);
  }
  v3 = 0i64;
  for ( i = this->agents_._Myfirst; v3 < this->agents_._Mylast - this->agents_._Myfirst; i = this->agents_._Myfirst )
  {
    v5 = i[v3];
    if ( v5 )
    {
      Myfirst = v5->orcaLines_._Myfirst;
      if ( Myfirst )
      {
        operator delete[](Myfirst);
        v5->orcaLines_._Myfirst = 0i64;
        v5->orcaLines_._Mylast = 0i64;
        v5->orcaLines_._Myend = 0i64;
      }
      v7 = v5->obstacleNeighbors_._Myfirst;
      if ( v7 )
      {
        operator delete[](v7);
        v5->obstacleNeighbors_._Myfirst = 0i64;
        v5->obstacleNeighbors_._Mylast = 0i64;
        v5->obstacleNeighbors_._Myend = 0i64;
      }
      if ( v5->agentNeighbors_._Myfirst )
      {
        operator delete[](v5->agentNeighbors_._Myfirst);
        v5->agentNeighbors_._Myfirst = 0i64;
        v5->agentNeighbors_._Mylast = 0i64;
        v5->agentNeighbors_._Myend = 0i64;
      }
      operator delete[](v5);
    }
    ++v3;
  }
  v8 = this->obstacles_._Myfirst;
  if ( v8 )
  {
    operator delete[](v8);
    this->obstacles_._Myfirst = 0i64;
    this->obstacles_._Mylast = 0i64;
    this->obstacles_._Myend = 0i64;
  }
  if ( this->agents_._Myfirst )
  {
    operator delete[](this->agents_._Myfirst);
    this->agents_._Myfirst = 0i64;
    this->agents_._Mylast = 0i64;
    this->agents_._Myend = 0i64;
  }
}

// File Line: 114
// RVA: 0xF79D0
signed __int64 __fastcall RVO::RVOSimulator::addAgent(RVO::RVOSimulator *this, RVO::Vector2 *position)
{
  char *v5; // rbx
  RVO::Agent **Mylast; // rcx
  signed __int64 v7; // rbx
  RVO::Agent **Myfirst; // rax
  RVO::Agent **v9; // rcx
  RVO::Agent **v10; // rax
  char *v11; // [rsp+50h] [rbp+8h] BYREF
  RVO::Agent **v12; // [rsp+60h] [rbp+18h]
  RVO::Agent **v13; // [rsp+68h] [rbp+20h]

  if ( !this->defaultAgent_ )
    return -1i64;
  v5 = UFG::qMalloc(0xB0ui64, UFG::gGlobalNewName, 0i64);
  v11 = v5;
  if ( v5 )
  {
    *(_QWORD *)v5 = 0i64;
    *((_QWORD *)v5 + 1) = 0i64;
    *((_QWORD *)v5 + 2) = 0i64;
    *((_QWORD *)v5 + 3) = 0i64;
    *((_QWORD *)v5 + 4) = 0i64;
    *((_QWORD *)v5 + 5) = 0i64;
    *((_QWORD *)v5 + 6) = 0i64;
    *((_QWORD *)v5 + 7) = 0i64;
    *((_QWORD *)v5 + 8) = 0i64;
    *((_QWORD *)v5 + 9) = 0i64;
    *((_QWORD *)v5 + 10) = 0i64;
    *((_QWORD *)v5 + 11) = 0i64;
    *((_QWORD *)v5 + 12) = 0i64;
    *((_QWORD *)v5 + 13) = 0i64;
    *((_DWORD *)v5 + 28) = 0;
    *((_QWORD *)v5 + 15) = this;
    *((_QWORD *)v5 + 16) = 0i64;
    *((_QWORD *)v5 + 17) = 0i64;
    *((_QWORD *)v5 + 18) = 0i64;
    v5[153] = 0;
    *(_QWORD *)(v5 + 156) = 0i64;
    *(_QWORD *)(v5 + 164) = 0i64;
  }
  else
  {
    v5 = 0i64;
  }
  v11 = v5;
  *((RVO::Vector2 *)v5 + 12) = *position;
  *((_QWORD *)v5 + 3) = this->defaultAgent_->maxNeighbors_;
  *((_DWORD *)v5 + 8) = LODWORD(this->defaultAgent_->maxSpeed_);
  *((_DWORD *)v5 + 9) = LODWORD(this->defaultAgent_->neighborDist_);
  *((_DWORD *)v5 + 28) = LODWORD(this->defaultAgent_->radius_);
  *((_DWORD *)v5 + 32) = LODWORD(this->defaultAgent_->timeHorizon_);
  *((_DWORD *)v5 + 33) = LODWORD(this->defaultAgent_->timeHorizonObst_);
  *((_QWORD *)v5 + 17) = this->defaultAgent_->velocity_;
  *((_QWORD *)v5 + 18) = this->agents_._Mylast - this->agents_._Myfirst;
  Mylast = this->agents_._Mylast;
  if ( &v11 >= (char **)Mylast || this->agents_._Myfirst > (RVO::Agent **)&v11 )
  {
    if ( Mylast == this->agents_._Myend )
      std::vector<RVO::Agent *>::_Reserve(&this->agents_, 1ui64);
    v10 = this->agents_._Mylast;
    if ( v10 )
      *v10 = (RVO::Agent *)v5;
  }
  else
  {
    v7 = ((char *)&v11 - (char *)this->agents_._Myfirst) >> 3;
    if ( Mylast == this->agents_._Myend )
      std::vector<RVO::Agent *>::_Reserve(&this->agents_, 1ui64);
    Myfirst = this->agents_._Myfirst;
    v9 = this->agents_._Mylast;
    v12 = v9;
    v13 = v9;
    if ( v9 )
      *v9 = Myfirst[v7];
  }
  ++this->agents_._Mylast;
  return this->agents_._Mylast - this->agents_._Myfirst - 1;
}

// File Line: 159
// RVA: 0xF9010
void __fastcall RVO::RVOSimulator::doStep(RVO::RVOSimulator *this)
{
  int v1; // ebp
  __int64 v3; // rsi
  RVO::Agent *v4; // rcx
  RVO::Agent *v5; // rbx
  RVO::Vector2 *v6; // rax
  RVO::Vector2 result; // [rsp+30h] [rbp+8h] BYREF

  v1 = 0;
  if ( (int)(this->agents_._Mylast - this->agents_._Myfirst) > 0 )
  {
    v3 = 0i64;
    do
    {
      v4 = this->agents_._Myfirst[v3];
      if ( v4->enabled )
      {
        RVO::Agent::computeNewVelocity(v4);
        v5 = this->agents_._Myfirst[v3];
        v5->velocity_ = v5->newVelocity_;
        v6 = RVO::Vector2::operator*(&v5->velocity_, &result, v5->sim_->timeStep_);
        v5->position_.x_ = v5->position_.x_ + v6->x_;
        v5->position_.y_ = v6->y_ + v5->position_.y_;
      }
      ++v1;
      ++v3;
    }
    while ( v1 < (int)(this->agents_._Mylast - this->agents_._Myfirst) );
  }
  this->globalTime_ = this->timeStep_ + this->globalTime_;
}

// File Line: 213
// RVA: 0xF9EC0
void __fastcall RVO::RVOSimulator::setAgentDefaults(
        RVO::RVOSimulator *this,
        float neighborDist,
        unsigned __int64 maxNeighbors,
        float timeHorizon,
        float timeHorizonObst,
        float radius,
        float maxSpeed,
        RVO::Vector2 *velocity)
{
  char *v10; // rax

  if ( !this->defaultAgent_ )
  {
    v10 = UFG::qMalloc(0xB0ui64, UFG::gGlobalNewName, 0i64);
    if ( v10 )
    {
      *(_QWORD *)v10 = 0i64;
      *((_QWORD *)v10 + 1) = 0i64;
      *((_QWORD *)v10 + 2) = 0i64;
      *((_QWORD *)v10 + 3) = 0i64;
      *((_QWORD *)v10 + 4) = 0i64;
      *((_QWORD *)v10 + 5) = 0i64;
      *((_QWORD *)v10 + 6) = 0i64;
      *((_QWORD *)v10 + 7) = 0i64;
      *((_QWORD *)v10 + 8) = 0i64;
      *((_QWORD *)v10 + 9) = 0i64;
      *((_QWORD *)v10 + 10) = 0i64;
      *((_QWORD *)v10 + 11) = 0i64;
      *((_QWORD *)v10 + 12) = 0i64;
      *((_QWORD *)v10 + 13) = 0i64;
      *((_DWORD *)v10 + 28) = 0;
      *((_QWORD *)v10 + 15) = this;
      *((_QWORD *)v10 + 16) = 0i64;
      *((_QWORD *)v10 + 17) = 0i64;
      *((_QWORD *)v10 + 18) = 0i64;
      v10[153] = 0;
      *(_QWORD *)(v10 + 156) = 0i64;
      *(_QWORD *)(v10 + 164) = 0i64;
    }
    else
    {
      v10 = 0i64;
    }
    this->defaultAgent_ = (RVO::Agent *)v10;
  }
  this->defaultAgent_->maxNeighbors_ = maxNeighbors;
  this->defaultAgent_->maxSpeed_ = maxSpeed;
  this->defaultAgent_->neighborDist_ = neighborDist;
  this->defaultAgent_->radius_ = radius;
  this->defaultAgent_->timeHorizon_ = timeHorizon;
  this->defaultAgent_->timeHorizonObst_ = timeHorizonObst;
  this->defaultAgent_->velocity_ = *velocity;
}

