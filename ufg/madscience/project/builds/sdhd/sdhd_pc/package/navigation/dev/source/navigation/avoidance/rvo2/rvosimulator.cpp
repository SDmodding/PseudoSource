// File Line: 86
// RVA: 0xF6430
void __fastcall RVO::RVOSimulator::~RVOSimulator(RVO::RVOSimulator *this)
{
  RVO::RVOSimulator *v1; // rdi
  RVO::Agent *v2; // rbx
  unsigned __int64 v3; // rsi
  RVO::Agent **v4; // rcx
  RVO::Agent *v5; // rbx
  RVO::Line *v6; // rcx
  std::pair<float,RVO::Obstacle const *> *v7; // rcx
  RVO::Obstacle **v8; // rcx

  v1 = this;
  v2 = this->defaultAgent_;
  if ( v2 )
  {
    RVO::Agent::~Agent(this->defaultAgent_);
    operator delete[](v2);
  }
  v3 = 0i64;
  v4 = v1->agents_._Myfirst;
  if ( (_QWORD)((char *)v1->agents_._Mylast - (char *)v1->agents_._Myfirst) >> 3 )
  {
    do
    {
      v5 = v4[v3];
      if ( v5 )
      {
        v6 = v5->orcaLines_._Myfirst;
        if ( v6 )
        {
          operator delete[](v6);
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
      v4 = v1->agents_._Myfirst;
    }
    while ( v3 < (_QWORD)((char *)v1->agents_._Mylast - (char *)v1->agents_._Myfirst) >> 3 );
  }
  v8 = v1->obstacles_._Myfirst;
  if ( v8 )
  {
    operator delete[](v8);
    v1->obstacles_._Myfirst = 0i64;
    v1->obstacles_._Mylast = 0i64;
    v1->obstacles_._Myend = 0i64;
  }
  if ( v1->agents_._Myfirst )
  {
    operator delete[](v1->agents_._Myfirst);
    v1->agents_._Myfirst = 0i64;
    v1->agents_._Mylast = 0i64;
    v1->agents_._Myend = 0i64;
  }
}

// File Line: 114
// RVA: 0xF79D0
signed __int64 __fastcall RVO::RVOSimulator::addAgent(RVO::RVOSimulator *this, RVO::Vector2 *position)
{
  RVO::Vector2 *v2; // rsi
  RVO::RVOSimulator *v3; // rdi
  char *v5; // rbx
  RVO::Agent **v6; // rcx
  signed __int64 v7; // rbx
  RVO::Agent **v8; // rax
  RVO::Agent **v9; // rcx
  _QWORD *v10; // rax
  char *v11; // [rsp+50h] [rbp+8h]
  RVO::Agent **v12; // [rsp+60h] [rbp+18h]
  RVO::Agent **v13; // [rsp+68h] [rbp+20h]

  v2 = position;
  v3 = this;
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
    *((_QWORD *)v5 + 15) = v3;
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
  *((RVO::Vector2 *)v5 + 12) = *v2;
  *((_QWORD *)v5 + 3) = v3->defaultAgent_->maxNeighbors_;
  *((_DWORD *)v5 + 8) = LODWORD(v3->defaultAgent_->maxSpeed_);
  *((_DWORD *)v5 + 9) = LODWORD(v3->defaultAgent_->neighborDist_);
  *((_DWORD *)v5 + 28) = LODWORD(v3->defaultAgent_->radius_);
  *((_DWORD *)v5 + 32) = LODWORD(v3->defaultAgent_->timeHorizon_);
  *((_DWORD *)v5 + 33) = LODWORD(v3->defaultAgent_->timeHorizonObst_);
  *((_QWORD *)v5 + 17) = v3->defaultAgent_->velocity_;
  *((_QWORD *)v5 + 18) = (_QWORD)((char *)v3->agents_._Mylast - (char *)v3->agents_._Myfirst) >> 3;
  v6 = v3->agents_._Mylast;
  if ( &v11 >= (char **)v6 || v3->agents_._Myfirst > (RVO::Agent **)&v11 )
  {
    if ( v6 == v3->agents_._Myend )
      std::vector<RVO::Agent *,std::allocator<RVO::Agent *>>::_Reserve(&v3->agents_, 1ui64);
    v10 = v3->agents_._Mylast;
    if ( v10 )
      *v10 = v5;
  }
  else
  {
    v7 = ((char *)&v11 - (char *)v3->agents_._Myfirst) >> 3;
    if ( v6 == v3->agents_._Myend )
      std::vector<RVO::Agent *,std::allocator<RVO::Agent *>>::_Reserve(&v3->agents_, 1ui64);
    v8 = v3->agents_._Myfirst;
    v9 = v3->agents_._Mylast;
    v12 = v9;
    v13 = v9;
    if ( v9 )
      *v9 = v8[v7];
  }
  ++v3->agents_._Mylast;
  return ((_QWORD)((char *)v3->agents_._Mylast - (char *)v3->agents_._Myfirst) >> 3) - 1i64;
}

// File Line: 159
// RVA: 0xF9010
void __fastcall RVO::RVOSimulator::doStep(RVO::RVOSimulator *this)
{
  signed int v1; // ebp
  RVO::RVOSimulator *v2; // rdi
  __int64 v3; // rsi
  RVO::Agent *v4; // rcx
  RVO::Agent *v5; // rbx
  RVO::Vector2 *v6; // rax
  RVO::Vector2 result; // [rsp+30h] [rbp+8h]

  v1 = 0;
  v2 = this;
  if ( (signed int)((_QWORD)((char *)this->agents_._Mylast - (char *)this->agents_._Myfirst) >> 3) > 0 )
  {
    v3 = 0i64;
    do
    {
      v4 = v2->agents_._Myfirst[v3];
      if ( v4->enabled )
      {
        RVO::Agent::computeNewVelocity(v4);
        v5 = v2->agents_._Myfirst[v3];
        v5->velocity_ = v5->newVelocity_;
        v6 = RVO::Vector2::operator*(&v5->velocity_, &result, v5->sim_->timeStep_);
        v5->position_.x_ = v5->position_.x_ + v6->x_;
        v5->position_.y_ = v6->y_ + v5->position_.y_;
      }
      ++v1;
      ++v3;
    }
    while ( v1 < (signed int)((_QWORD)((char *)v2->agents_._Mylast - (char *)v2->agents_._Myfirst) >> 3) );
  }
  v2->globalTime_ = v2->timeStep_ + v2->globalTime_;
}

// File Line: 213
// RVA: 0xF9EC0
void __fastcall RVO::RVOSimulator::setAgentDefaults(RVO::RVOSimulator *this, float neighborDist, unsigned __int64 maxNeighbors, float timeHorizon, float timeHorizonObst, float radius, float maxSpeed, RVO::Vector2 *velocity)
{
  unsigned __int64 v8; // rdi
  RVO::RVOSimulator *v9; // rbx
  char *v10; // rax

  v8 = maxNeighbors;
  v9 = this;
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
      *((_QWORD *)v10 + 15) = v9;
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
    v9->defaultAgent_ = (RVO::Agent *)v10;
  }
  v9->defaultAgent_->maxNeighbors_ = v8;
  v9->defaultAgent_->maxSpeed_ = maxSpeed;
  v9->defaultAgent_->neighborDist_ = neighborDist;
  v9->defaultAgent_->radius_ = radius;
  v9->defaultAgent_->timeHorizon_ = timeHorizon;
  v9->defaultAgent_->timeHorizonObst_ = timeHorizonObst;
  v9->defaultAgent_->velocity_ = *velocity;
}

