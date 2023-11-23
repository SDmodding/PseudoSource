// File Line: 91
// RVA: 0xF6320
void __fastcall RVO::Agent::~Agent(RVO::Agent *this)
{
  RVO::Line *Myfirst; // rcx
  std::pair<float,RVO::Obstacle const *> *v3; // rcx

  Myfirst = this->orcaLines_._Myfirst;
  if ( Myfirst )
  {
    operator delete[](Myfirst);
    this->orcaLines_._Myfirst = 0i64;
    this->orcaLines_._Mylast = 0i64;
    this->orcaLines_._Myend = 0i64;
  }
  v3 = this->obstacleNeighbors_._Myfirst;
  if ( v3 )
  {
    operator delete[](v3);
    this->obstacleNeighbors_._Myfirst = 0i64;
    this->obstacleNeighbors_._Mylast = 0i64;
    this->obstacleNeighbors_._Myend = 0i64;
  }
  if ( this->agentNeighbors_._Myfirst )
  {
    operator delete[](this->agentNeighbors_._Myfirst);
    this->agentNeighbors_._Myfirst = 0i64;
    this->agentNeighbors_._Mylast = 0i64;
    this->agentNeighbors_._Myend = 0i64;
  }
}

// File Line: 96
// RVA: 0xF7BA0
void __fastcall RVO::Agent::computeNewVelocity(RVO::Agent *this)
{
  RVO::Agent *v1; // r15
  int v2; // edi
  std::vector<RVO::Line> *p_orcaLines; // rsi
  float v4; // xmm14_4
  float v5; // xmm15_4
  RVO::Vector2 v6; // rcx
  int v7; // xmm13_4
  RVO::Vector2 *p_position; // rbx
  float v9; // xmm7_4
  RVO::Obstacle *second; // r12
  RVO::Obstacle *nextObstacle; // r13
  unsigned __int64 v12; // r15
  float v13; // xmm6_4
  float *p_direction; // rbx
  RVO::Vector2 *v15; // rax
  RVO::Vector2 *v16; // rax
  RVO::Vector2 *v17; // rax
  RVO::Vector2 *v18; // rax
  bool v19; // al
  __m128 y_low; // xmm10
  float x; // xmm11_4
  __m128 v22; // xmm13
  __m128 v23; // xmm8
  float v24; // xmm12_4
  __m128 v25; // xmm14
  float v26; // xmm9_4
  float v27; // xmm6_4
  RVO::Vector2 *v28; // rax
  float v29; // xmm7_4
  RVO::Vector2 *v30; // rbx
  RVO::Vector2 *v31; // rax
  RVO::Vector2 *v32; // rax
  float v33; // xmm1_4
  __m128 v34; // xmm0
  float v35; // xmm1_4
  float v36; // xmm6_4
  float v37; // xmm7_4
  float v38; // xmm2_4
  float v39; // xmm11_4
  float v40; // xmm10_4
  RVO::Vector2 v41; // rbx
  __m128 v42; // xmm0
  float v43; // xmm1_4
  float v44; // xmm6_4
  float v45; // xmm7_4
  float v46; // xmm2_4
  float v47; // xmm12_4
  float v48; // xmm8_4
  __m128 v49; // xmm0
  float v50; // xmm1_4
  RVO::Vector2 *v51; // rax
  __m128 v52; // xmm0
  float v53; // xmm1_4
  RVO::Vector2 *prevObstacle; // r14
  float y; // xmm7_4
  float v56; // xmm8_4
  RVO::Vector2 *v57; // rax
  bool v58; // al
  RVO::Vector2 *v59; // rax
  RVO::Vector2 *v60; // rax
  float v61; // xmm6_4
  RVO::Vector2 *v62; // rax
  RVO::Vector2 *v63; // rax
  float v64; // xmm7_4
  RVO::Vector2 *v65; // rax
  float v66; // xmm10_4
  RVO::Vector2 *v67; // rax
  RVO::Vector2 *v68; // rax
  RVO::Vector2 *v69; // rax
  RVO::Vector2 *v70; // rax
  RVO::Vector2 *v71; // rdx
  RVO::Vector2 *v72; // rcx
  RVO::Vector2 *v73; // rax
  RVO::Vector2 *v74; // rax
  RVO::Vector2 *v75; // rax
  float Float; // xmm8_4
  float v77; // xmm6_4
  RVO::Vector2 *v78; // rax
  RVO::Vector2 *v79; // rax
  RVO::Vector2 *v80; // rax
  float v81; // xmm1_4
  RVO::Vector2 *v82; // rax
  RVO::Vector2 *v83; // rax
  RVO::Vector2 *v84; // rax
  __int64 v85; // r13
  float v86; // xmm11_4
  unsigned __int64 v87; // rdi
  __int64 v88; // r14
  RVO::Vector2 *v89; // rbx
  __m128 v90; // xmm7
  float v91; // xmm9_4
  __m128 v92; // xmm6
  float v93; // xmm8_4
  float v94; // xmm10_4
  RVO::Vector2 *v95; // rax
  __m128 v96; // xmm3
  float v97; // xmm1_4
  float v98; // xmm6_4
  RVO::Vector2 direction; // rax
  RVO::Vector2 *p_vector; // r8
  float v101; // xmm1_4
  RVO::Vector2 *v102; // rcx
  __m128 v103; // xmm0
  float v104; // xmm3_4
  float v105; // xmm1_4
  float v106; // xmm3_4
  float v107; // xmm0_4
  float v108; // xmm8_4
  RVO::Vector2 *v109; // rdx
  RVO::Vector2 *v110; // rcx
  RVO::Vector2 *v111; // rax
  RVO::Vector2 *v112; // rax
  float v113; // xmm7_4
  RVO::Vector2 *v114; // rax
  __m128 v115; // xmm1
  float v116; // xmm6_4
  RVO::Vector2 *v117; // rax
  RVO::Line *Mylast; // rcx
  RVO::Line *Myfirst; // r8
  unsigned __int64 v120; // rbx
  RVO::Line *v121; // rdx
  __int64 v122; // rcx
  unsigned __int64 v123; // rdx
  unsigned __int64 v124; // rdx
  float *v125; // rbx
  RVO::Line *v126; // rcx
  RVO::Line *Myend; // rdx
  __int64 v128; // rcx
  unsigned __int64 v129; // rdx
  unsigned __int64 v130; // rdx
  RVO::Line *v131; // rax
  unsigned __int64 v132; // rax
  RVO::Line _Val; // [rsp+38h] [rbp-88h] BYREF
  RVO::Vector2 v134; // [rsp+48h] [rbp-78h] BYREF
  RVO::Vector2 v135; // [rsp+50h] [rbp-70h] BYREF
  RVO::Vector2 v136; // [rsp+58h] [rbp-68h] BYREF
  RVO::Vector2 v137; // [rsp+60h] [rbp-60h] BYREF
  RVO::Vector2 vector; // [rsp+68h] [rbp-58h] BYREF
  RVO::Vector2 v139; // [rsp+70h] [rbp-50h] BYREF
  RVO::Vector2 result; // [rsp+78h] [rbp-48h] BYREF
  RVO::Vector2 v141; // [rsp+80h] [rbp-40h] BYREF
  RVO::Vector2 v142; // [rsp+88h] [rbp-38h] BYREF
  RVO::Vector2 v143; // [rsp+90h] [rbp-30h] BYREF
  __int64 v144; // [rsp+98h] [rbp-28h]
  RVO::Vector2 v145; // [rsp+A0h] [rbp-20h] BYREF
  RVO::Vector2 v146; // [rsp+A8h] [rbp-18h]
  __int64 v147; // [rsp+B0h] [rbp-10h]
  RVO::Vector2 v148; // [rsp+B8h] [rbp-8h] BYREF
  RVO::Vector2 v149; // [rsp+C0h] [rbp+0h] BYREF
  RVO::Vector2 v150; // [rsp+C8h] [rbp+8h]
  RVO::Vector2 v151; // [rsp+D0h] [rbp+10h] BYREF
  __int64 v152; // [rsp+D8h] [rbp+18h]
  RVO::Vector2 v153; // [rsp+E0h] [rbp+20h] BYREF
  RVO::Vector2 v154; // [rsp+E8h] [rbp+28h] BYREF
  RVO::Vector2 v155; // [rsp+F0h] [rbp+30h] BYREF
  RVO::Vector2 v156; // [rsp+F8h] [rbp+38h] BYREF
  RVO::Vector2 v157; // [rsp+100h] [rbp+40h] BYREF
  RVO::Vector2 v158; // [rsp+108h] [rbp+48h] BYREF
  RVO::Vector2 v159; // [rsp+110h] [rbp+50h] BYREF
  RVO::Vector2 v160; // [rsp+118h] [rbp+58h] BYREF
  RVO::Vector2 v161; // [rsp+120h] [rbp+60h] BYREF
  RVO::Vector2 v162; // [rsp+128h] [rbp+68h] BYREF
  RVO::Vector2 v163; // [rsp+130h] [rbp+70h] BYREF
  RVO::Vector2 v164; // [rsp+138h] [rbp+78h] BYREF
  RVO::Vector2 v165; // [rsp+140h] [rbp+80h] BYREF
  RVO::Vector2 v166; // [rsp+148h] [rbp+88h] BYREF
  RVO::Vector2 v167; // [rsp+150h] [rbp+90h] BYREF
  RVO::Vector2 v168; // [rsp+158h] [rbp+98h] BYREF
  RVO::Vector2 v169; // [rsp+160h] [rbp+A0h] BYREF
  RVO::Vector2 v170; // [rsp+168h] [rbp+A8h] BYREF
  RVO::Vector2 v171; // [rsp+170h] [rbp+B0h] BYREF
  RVO::Vector2 v172; // [rsp+178h] [rbp+B8h] BYREF
  RVO::Vector2 v173; // [rsp+180h] [rbp+C0h] BYREF
  RVO::Vector2 v174; // [rsp+188h] [rbp+C8h] BYREF
  RVO::Vector2 v175; // [rsp+190h] [rbp+D0h] BYREF
  RVO::Vector2 v176; // [rsp+198h] [rbp+D8h] BYREF
  RVO::Vector2 v177; // [rsp+1A0h] [rbp+E0h] BYREF
  RVO::Vector2 v178; // [rsp+1A8h] [rbp+E8h] BYREF
  RVO::Vector2 v179; // [rsp+1B0h] [rbp+F0h] BYREF
  RVO::Vector2 v180; // [rsp+1B8h] [rbp+F8h] BYREF
  RVO::Vector2 v181; // [rsp+1C0h] [rbp+100h] BYREF
  RVO::Vector2 v182; // [rsp+1C8h] [rbp+108h] BYREF
  RVO::Vector2 v183; // [rsp+1D0h] [rbp+110h] BYREF
  RVO::Vector2 v184; // [rsp+1D8h] [rbp+118h] BYREF
  RVO::Vector2 v185; // [rsp+1E0h] [rbp+120h] BYREF
  RVO::Vector2 v186; // [rsp+1E8h] [rbp+128h] BYREF
  RVO::Vector2 v187; // [rsp+1F0h] [rbp+130h] BYREF
  RVO::Vector2 v188; // [rsp+1F8h] [rbp+138h] BYREF
  RVO::Vector2 v189; // [rsp+200h] [rbp+140h] BYREF
  RVO::Vector2 v190; // [rsp+208h] [rbp+148h] BYREF
  RVO::Vector2 v191; // [rsp+210h] [rbp+150h] BYREF
  RVO::Vector2 v192; // [rsp+218h] [rbp+158h] BYREF
  RVO::Vector2 v193; // [rsp+220h] [rbp+160h] BYREF
  __int64 v194; // [rsp+228h] [rbp+168h]
  RVO::Vector2 v195; // [rsp+230h] [rbp+170h] BYREF
  RVO::Vector2 v196; // [rsp+238h] [rbp+178h] BYREF
  RVO::Vector2 v197; // [rsp+240h] [rbp+180h] BYREF
  RVO::Vector2 v198; // [rsp+248h] [rbp+188h] BYREF
  RVO::Vector2 v199; // [rsp+250h] [rbp+190h] BYREF
  RVO::Vector2 v200; // [rsp+258h] [rbp+198h] BYREF
  RVO::Vector2 v201; // [rsp+350h] [rbp+290h] BYREF
  RVO::Vector2 v202; // [rsp+358h] [rbp+298h] BYREF
  RVO::Vector2 v203; // [rsp+360h] [rbp+2A0h] BYREF
  RVO::Vector2 unitDir; // [rsp+368h] [rbp+2A8h] BYREF

  v194 = -2i64;
  v1 = this;
  v2 = 0;
  p_orcaLines = &this->orcaLines_;
  this->orcaLines_._Mylast = this->orcaLines_._Myfirst;
  v4 = *(float *)&FLOAT_1_0;
  v5 = 1.0 / this->timeHorizonObst_;
  v6 = 0i64;
  v135 = 0i64;
  v7 = _xmm[0];
  if ( v1->obstacleNeighbors_._Mylast - v1->obstacleNeighbors_._Myfirst )
  {
    p_position = &v1->position_;
    v9 = FLOAT_N0_0000099999997;
    while ( 1 )
    {
      second = v1->obstacleNeighbors_._Myfirst[*(_QWORD *)&v6].second;
      nextObstacle = second->nextObstacle;
      RVO::Vector2::operator-(&second->point_, &result, p_position);
      RVO::Vector2::operator-(&nextObstacle->point_, &vector, p_position);
      v12 = 0i64;
      if ( p_orcaLines->_Mylast - p_orcaLines->_Myfirst )
      {
        v13 = v5 * *(float *)(*(_QWORD *)&v201 + 112i64);
        p_direction = (float *)&p_orcaLines->_Myfirst->direction;
        while ( 1 )
        {
          v2 |= 3u;
          v15 = RVO::operator*(&v174, v5, &result);
          v16 = RVO::Vector2::operator-(v15, &v176, (RVO::Vector2 *)p_direction - 1);
          v19 = 0;
          if ( (float)((float)((float)(p_direction[1] * v16->x_) - (float)(*p_direction * v16->y_)) - v13) >= v9 )
          {
            v2 |= 0xCu;
            v17 = RVO::operator*(&v178, v5, &vector);
            v18 = RVO::Vector2::operator-(v17, &v180, (RVO::Vector2 *)p_direction - 1);
            if ( (float)((float)((float)(p_direction[1] * v18->x_) - (float)(*p_direction * v18->y_)) - v13) >= v9 )
              v19 = 1;
          }
          if ( (v2 & 8) != 0 )
            v2 &= ~8u;
          if ( (v2 & 4) != 0 )
            v2 &= ~4u;
          if ( (v2 & 2) != 0 )
            v2 &= ~2u;
          if ( (v2 & 1) != 0 )
            v2 &= ~1u;
          if ( v19 )
            break;
          ++v12;
          p_direction += 4;
          if ( v12 >= p_orcaLines->_Mylast - p_orcaLines->_Myfirst )
            goto LABEL_19;
        }
        v1 = (RVO::Agent *)v201;
        goto LABEL_115;
      }
LABEL_19:
      y_low = (__m128)LODWORD(result.y_);
      v22 = y_low;
      x = result.x_;
      v22.m128_f32[0] = (float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(x * x);
      v23 = (__m128)LODWORD(vector.y_);
      v25 = v23;
      v24 = vector.x_;
      v25.m128_f32[0] = (float)(v23.m128_f32[0] * v23.m128_f32[0]) + (float)(v24 * v24);
      v1 = (RVO::Agent *)v201;
      v26 = *(float *)(*(_QWORD *)&v201 + 112i64);
      v27 = v26 * v26;
      RVO::Vector2::operator-(&nextObstacle->point_, &v137, &second->point_);
      v28 = RVO::Vector2::operator-(&result, &v182);
      v29 = (float)((float)(v137.y_ * v28->y_) + (float)(v137.x_ * v28->x_))
          / (float)((float)(v137.y_ * v137.y_) + (float)(v137.x_ * v137.x_));
      v30 = RVO::operator*(&v184, v29, &v137);
      v31 = RVO::Vector2::operator-(&result, &v186);
      v32 = RVO::Vector2::operator-(v31, &v188, v30);
      v33 = (float)(v32->y_ * v32->y_) + (float)(v32->x_ * v32->x_);
      _Val.point = 0i64;
      _Val.direction = 0i64;
      if ( v29 < 0.0 && v22.m128_f32[0] <= v27 )
      {
        v7 = _xmm[0];
        if ( second->isConvex_ )
        {
          v152 = 0i64;
          _Val.point = 0i64;
          LODWORD(v148.x_) = y_low.m128_i32[0] ^ _xmm[0];
          v148.y_ = x;
          _Val.direction = *RVO::normalize(&v190, &v148);
          std::vector<RVO::Line>::push_back(p_orcaLines, &_Val);
        }
        goto LABEL_23;
      }
      if ( v29 <= 1.0 || v25.m128_f32[0] > v27 )
        break;
      if ( !nextObstacle->isConvex_ )
        goto LABEL_33;
      v7 = _xmm[0];
      if ( (float)((float)(v24 * nextObstacle->unitDir_.y_) - (float)(v23.m128_f32[0] * nextObstacle->unitDir_.x_)) >= 0.0 )
      {
        v144 = 0i64;
        _Val.point = 0i64;
        LODWORD(v145.x_) = v23.m128_i32[0] ^ _xmm[0];
        v145.y_ = v24;
        _Val.direction = *RVO::normalize(&v192, &v145);
        std::vector<RVO::Line>::push_back(p_orcaLines, &_Val);
        v9 = FLOAT_N0_0000099999997;
        v4 = *(float *)&FLOAT_1_0;
        goto LABEL_115;
      }
LABEL_23:
      v9 = FLOAT_N0_0000099999997;
      v4 = *(float *)&FLOAT_1_0;
LABEL_115:
      v6 = (RVO::Vector2)(*(_QWORD *)&v135 + 1i64);
      v135 = v6;
      p_position = &v1->position_;
      if ( *(unsigned __int64 *)&v6 >= v1->obstacleNeighbors_._Mylast - v1->obstacleNeighbors_._Myfirst )
        goto LABEL_116;
    }
    if ( v29 < 0.0 )
      goto LABEL_35;
    if ( v29 < 1.0 && v33 <= v27 )
    {
      v147 = 0i64;
      _Val.point = 0i64;
      _Val.direction = *RVO::Vector2::operator-(&second->unitDir_, &v165);
      std::vector<RVO::Line>::push_back(p_orcaLines, &_Val);
LABEL_33:
      v7 = _xmm[0];
      goto LABEL_23;
    }
    if ( v29 < 0.0 )
    {
LABEL_35:
      if ( v33 <= v27 )
      {
        if ( second->isConvex_ )
        {
          nextObstacle = second;
          v34 = v22;
          v34.m128_f32[0] = v22.m128_f32[0] - v27;
          v35 = _mm_sqrt_ps(v34).m128_f32[0];
          v36 = x * v26;
          v37 = y_low.m128_f32[0] * v35;
          v38 = (float)(y_low.m128_f32[0] * v35) + (float)(x * v26);
          v39 = x * v35;
          v40 = y_low.m128_f32[0] * v26;
          v149.x_ = v39 - v40;
          v149.y_ = v38;
          v41 = *RVO::Vector2::operator/(&v149, &v196, v22.m128_f32[0]);
          v134 = v41;
          v141.x_ = v40 + v39;
          v141.y_ = v37 - v36;
          unitDir = *RVO::Vector2::operator/(&v141, &v198, v22.m128_f32[0]);
          goto LABEL_48;
        }
        goto LABEL_33;
      }
    }
    if ( v29 <= 1.0 || v33 > v27 )
    {
      if ( second->isConvex_ )
      {
        v49 = v22;
        v49.m128_f32[0] = v22.m128_f32[0] - v27;
        v50 = _mm_sqrt_ps(v49).m128_f32[0];
        v153.x_ = (float)(x * v50) - (float)(y_low.m128_f32[0] * v26);
        v153.y_ = (float)(x * v26) + (float)(y_low.m128_f32[0] * v50);
        v51 = RVO::Vector2::operator/(&v153, &v199, v22.m128_f32[0]);
      }
      else
      {
        v51 = RVO::Vector2::operator-(&second->unitDir_, &v169);
      }
      v41 = *v51;
      v134 = *v51;
      if ( nextObstacle->isConvex_ )
      {
        v52 = v25;
        v52.m128_f32[0] = v25.m128_f32[0] - v27;
        v53 = _mm_sqrt_ps(v52).m128_f32[0];
        v139.x_ = (float)(v23.m128_f32[0] * v26) + (float)(v24 * v53);
        v139.y_ = (float)(v23.m128_f32[0] * v53) - (float)(v24 * v26);
        unitDir = *RVO::Vector2::operator/(&v139, &v185, v25.m128_f32[0]);
      }
      else
      {
        unitDir = second->unitDir_;
      }
LABEL_48:
      prevObstacle = (RVO::Vector2 *)second->prevObstacle;
      LOBYTE(v202.x_) = 0;
      LOBYTE(v203.x_) = 0;
      y = v134.y_;
      v56 = v134.x_;
      v58 = 0;
      if ( second->isConvex_ )
      {
        v2 |= 0x10u;
        v57 = RVO::Vector2::operator-(prevObstacle + 4, &v171);
        if ( (float)((float)(v57->y_ * v56) - (float)(v57->x_ * y)) >= 0.0 )
          v58 = 1;
      }
      if ( (v2 & 0x10) != 0 )
        v2 &= ~0x10u;
      if ( v58 )
      {
        v41 = *RVO::Vector2::operator-(prevObstacle + 4, &v193);
        v134 = v41;
        LOBYTE(v202.x_) = 1;
        y = v41.y_;
        v56 = v41.x_;
      }
      if ( nextObstacle->isConvex_
        && (float)((float)(nextObstacle->unitDir_.y_ * unitDir.x_) - (float)(nextObstacle->unitDir_.x_ * unitDir.y_)) <= 0.0 )
      {
        unitDir = nextObstacle->unitDir_;
        LOBYTE(v203.x_) = 1;
      }
      v59 = RVO::Vector2::operator-(&second->point_, &v173, &v1->position_);
      RVO::operator*(&v135, v5, v59);
      v60 = RVO::Vector2::operator-(&nextObstacle->point_, &v187, &v1->position_);
      RVO::operator*(&v139, v5, v60);
      RVO::Vector2::operator-(&v139, &v137, &v135);
      if ( second == nextObstacle )
      {
        v61 = FLOAT_0_5;
      }
      else
      {
        v2 |= 0x20u;
        v62 = RVO::Vector2::operator-(&v1->velocity_, &v175, &v135);
        v61 = (float)((float)(v137.y_ * v62->y_) + (float)(v137.x_ * v62->x_))
            / (float)((float)(v137.y_ * v137.y_) + (float)(v137.x_ * v137.x_));
      }
      if ( (v2 & 0x20) != 0 )
        v2 &= ~0x20u;
      v63 = RVO::Vector2::operator-(&v1->velocity_, &v197, &v135);
      v64 = (float)(y * v63->y_) + (float)(v56 * v63->x_);
      v65 = RVO::Vector2::operator-(&v1->velocity_, &v177, &v139);
      v66 = (float)(unitDir.y_ * v65->y_) + (float)(unitDir.x_ * v65->x_);
      if ( (v61 >= 0.0 || v64 >= 0.0) && (second != nextObstacle || v64 >= 0.0 || v66 >= 0.0) )
      {
        v4 = *(float *)&FLOAT_1_0;
        if ( v61 > 1.0 && v66 < 0.0 )
        {
          v69 = RVO::Vector2::operator-(&v1->velocity_, &v181, &v139);
          RVO::normalize(&vector, v69);
          v150.x_ = vector.y_;
          v7 = _xmm[0];
          LODWORD(v150.y_) = LODWORD(vector.x_) ^ _xmm[0];
          _Val.direction = v150;
          v70 = RVO::operator*(&v191, v26 * v5, &vector);
          v71 = &v183;
          goto LABEL_73;
        }
        if ( v61 < 0.0 || v61 > 1.0 || second == nextObstacle )
        {
          Float = FInf._Float;
        }
        else
        {
          v2 |= 0x1C0u;
          v73 = RVO::operator*(&v166, v61, &v137);
          v74 = RVO::Vector2::operator+(&v135, &v168, v73);
          v75 = RVO::Vector2::operator-(&v1->velocity_, &v170, v74);
          Float = (float)(v75->y_ * v75->y_) + (float)(v75->x_ * v75->x_);
        }
        if ( (v2 & 0x100) != 0 )
          v2 &= ~0x100u;
        if ( (v2 & 0x80u) != 0 )
          v2 &= ~0x80u;
        if ( (v2 & 0x40) != 0 )
          v2 &= ~0x40u;
        if ( v64 >= 0.0 )
        {
          v2 |= 0xE00u;
          v78 = RVO::operator*(&v172, v64, &v134);
          v79 = RVO::Vector2::operator+(&v135, &result, v78);
          v80 = RVO::Vector2::operator-(&v1->velocity_, &v142, v79);
          v77 = (float)(v80->y_ * v80->y_) + (float)(v80->x_ * v80->x_);
        }
        else
        {
          v77 = FInf._Float;
        }
        if ( (v2 & 0x800) != 0 )
          v2 &= ~0x800u;
        if ( (v2 & 0x400) != 0 )
          v2 &= ~0x400u;
        if ( (v2 & 0x200) != 0 )
          v2 &= ~0x200u;
        if ( v66 >= 0.0 )
        {
          v2 |= 0x7000u;
          v82 = RVO::operator*(&v154, v66, &unitDir);
          v83 = RVO::Vector2::operator+(&v139, &v163, v82);
          v84 = RVO::Vector2::operator-(&v1->velocity_, &v157, v83);
          v81 = (float)(v84->y_ * v84->y_) + (float)(v84->x_ * v84->x_);
        }
        else
        {
          v81 = FInf._Float;
        }
        if ( (v2 & 0x4000) != 0 )
          v2 &= ~0x4000u;
        if ( (v2 & 0x2000) != 0 )
          v2 &= ~0x2000u;
        if ( (v2 & 0x1000) != 0 )
          v2 &= ~0x1000u;
        if ( Float <= v77 && Float <= v81 )
        {
          LODWORD(_Val.direction.y_) = HIDWORD(*(unsigned __int64 *)RVO::Vector2::operator-(&second->unitDir_, &v161));
          v7 = _xmm[0];
          LODWORD(_Val.direction.x_) = LODWORD(_Val.direction.y_) ^ _xmm[0];
          LODWORD(_Val.direction.y_) ^= _xmm[0];
          v70 = RVO::operator*(&v159, v26 * v5, &_Val.direction);
          v71 = &v155;
          v72 = &v135;
          goto LABEL_74;
        }
        if ( v77 > v81 )
        {
          if ( LOBYTE(v203.x_) )
          {
            v7 = _xmm[0];
          }
          else
          {
            _Val.direction = *RVO::Vector2::operator-(&unitDir, &v160);
            v7 = _xmm[0];
            LODWORD(v136.x_) = LODWORD(_Val.direction.y_) ^ _xmm[0];
            v136.y_ = _Val.direction.x_;
            v70 = RVO::operator*(&v162, v26 * v5, &v136);
            v71 = &v164;
LABEL_73:
            v72 = &v139;
LABEL_74:
            _Val.point = *RVO::Vector2::operator+(v72, v71, v70);
            std::vector<RVO::Line>::push_back(p_orcaLines, &_Val);
          }
        }
        else
        {
          v7 = _xmm[0];
          if ( !LOBYTE(v202.x_) )
          {
            _Val.direction = v41;
            LODWORD(v134.x_) = LODWORD(v41.y_) ^ _xmm[0];
            v134.y_ = v41.x_;
            v70 = RVO::operator*(&v156, v26 * v5, &v134);
            v71 = &v158;
            v72 = &v135;
            goto LABEL_74;
          }
        }
        v9 = FLOAT_N0_0000099999997;
        goto LABEL_115;
      }
      v67 = RVO::Vector2::operator-(&v1->velocity_, &v189, &v135);
      RVO::normalize(&v136, v67);
      v146.x_ = v136.y_;
      v7 = _xmm[0];
      LODWORD(v146.y_) = LODWORD(v136.x_) ^ _xmm[0];
      _Val.direction = v146;
      v68 = RVO::operator*(&v179, v26 * v5, &v136);
      _Val.point = *RVO::Vector2::operator+(&v135, &v195, v68);
      std::vector<RVO::Line>::push_back(p_orcaLines, &_Val);
      goto LABEL_23;
    }
    if ( nextObstacle->isConvex_ )
    {
      second = nextObstacle;
      v42 = v25;
      v42.m128_f32[0] = v25.m128_f32[0] - v27;
      v43 = _mm_sqrt_ps(v42).m128_f32[0];
      v44 = v24 * v26;
      v45 = v23.m128_f32[0] * v43;
      v46 = (float)(v23.m128_f32[0] * v43) + (float)(v24 * v26);
      v47 = v24 * v43;
      v48 = v23.m128_f32[0] * v26;
      v151.x_ = v47 - v48;
      v151.y_ = v46;
      v41 = *RVO::Vector2::operator/(&v151, &v200, v25.m128_f32[0]);
      v134 = v41;
      v143.x_ = v48 + v47;
      v143.y_ = v45 - v44;
      unitDir = *RVO::Vector2::operator/(&v143, &v167, v25.m128_f32[0]);
      goto LABEL_48;
    }
    goto LABEL_33;
  }
LABEL_116:
  v85 = p_orcaLines->_Mylast - p_orcaLines->_Myfirst;
  v86 = v4 / v1->timeHorizon_;
  v87 = 0i64;
  if ( v1->agentNeighbors_._Mylast - v1->agentNeighbors_._Myfirst )
  {
    v88 = 0i64;
    do
    {
      v89 = (RVO::Vector2 *)v1->agentNeighbors_._Myfirst[v88].second;
      RVO::Vector2::operator-(v89 + 12, &v202, &v1->position_);
      RVO::Vector2::operator-(&v1->velocity_, &v201, v89 + 17);
      v90 = (__m128)LODWORD(v202.y_);
      v92 = v90;
      v91 = v202.x_;
      v92.m128_f32[0] = (float)(v90.m128_f32[0] * v90.m128_f32[0]) + (float)(v91 * v91);
      v93 = v89[14].x_ + v1->radius_;
      v94 = v93 * v93;
      _Val.point = 0i64;
      if ( v92.m128_f32[0] <= (float)(v93 * v93) )
      {
        v113 = v4 / v1->sim_->timeStep_;
        v114 = RVO::operator*(&v161, v113, &v202);
        RVO::Vector2::operator-(&v201, &v137, v114);
        v115 = (__m128)LODWORD(v137.y_);
        v115.m128_f32[0] = (float)(v115.m128_f32[0] * v115.m128_f32[0]) + (float)(v137.x_ * v137.x_);
        v116 = _mm_sqrt_ps(v115).m128_f32[0];
        RVO::Vector2::operator/(&v137, &vector, v116);
        _Val.direction.x_ = vector.y_;
        LODWORD(_Val.direction.y_) = LODWORD(vector.x_) ^ v7;
        direction = _Val.direction;
        p_vector = &vector;
        v101 = (float)(v113 * v93) - v116;
        v102 = &v157;
      }
      else
      {
        v95 = RVO::operator*(&v164, v86, &v202);
        RVO::Vector2::operator-(&v201, &v203, v95);
        v96 = (__m128)LODWORD(v203.y_);
        v96.m128_f32[0] = (float)(v96.m128_f32[0] * v96.m128_f32[0]) + (float)(v203.x_ * v203.x_);
        v97 = (float)(v203.y_ * v90.m128_f32[0]) + (float)(v203.x_ * v91);
        if ( v97 >= 0.0 || (float)(v97 * v97) <= (float)(v96.m128_f32[0] * v94) )
        {
          v103 = v92;
          v103.m128_f32[0] = v92.m128_f32[0] - v94;
          v104 = _mm_sqrt_ps(v103).m128_f32[0];
          v105 = v104 * v91;
          v106 = v104 * v90.m128_f32[0];
          v107 = v93 * v90.m128_f32[0];
          v108 = v93 * v91;
          if ( (float)((float)(v203.y_ * v91) - (float)(v203.x_ * v90.m128_f32[0])) <= 0.0 )
          {
            v134.x_ = v105 + v107;
            v134.y_ = v106 - v108;
            v110 = RVO::Vector2::operator-(&v134, &v158);
            v109 = &v156;
          }
          else
          {
            v136.x_ = v105 - v107;
            v136.y_ = v106 + v108;
            v109 = &v160;
            v110 = &v136;
          }
          _Val.direction = *RVO::Vector2::operator/(v110, v109, v92.m128_f32[0]);
          v111 = RVO::operator*(
                   &v155,
                   (float)(v201.y_ * _Val.direction.y_) + (float)(v201.x_ * _Val.direction.x_),
                   &_Val.direction);
          v112 = RVO::Vector2::operator-(v111, &v159, &v201);
          goto LABEL_128;
        }
        v98 = _mm_sqrt_ps(v96).m128_f32[0];
        RVO::Vector2::operator/(&v203, &unitDir, v98);
        v135.x_ = unitDir.y_;
        LODWORD(v135.y_) = LODWORD(unitDir.x_) ^ v7;
        direction = v135;
        p_vector = &unitDir;
        v101 = (float)(v93 * v86) - v98;
        v102 = &v162;
      }
      _Val.direction = direction;
      v112 = RVO::operator*(v102, v101, p_vector);
LABEL_128:
      v136 = *v112;
      v117 = RVO::operator*(&v163, 0.5, &v136);
      _Val.point = *RVO::Vector2::operator+(&v1->velocity_, &v154, v117);
      Mylast = p_orcaLines->_Mylast;
      if ( &_Val >= Mylast || (Myfirst = p_orcaLines->_Myfirst, p_orcaLines->_Myfirst > &_Val) )
      {
        Myend = p_orcaLines->_Myend;
        if ( Mylast == Myend && !(Myend - Mylast) )
        {
          v128 = Mylast - p_orcaLines->_Myfirst;
          if ( v128 == 0xFFFFFFFFFFFFFFFi64 )
            std::_Xlength_error("vector<T> too long");
          v129 = Myend - p_orcaLines->_Myfirst;
          if ( 0xFFFFFFFFFFFFFFFi64 - (v129 >> 1) >= v129 )
            v130 = (v129 >> 1) + v129;
          else
            v130 = 0i64;
          if ( v130 < v128 + 1 )
            v130 = v128 + 1;
          std::vector<RVO::Line>::_Reallocate(p_orcaLines, v130);
        }
        v131 = p_orcaLines->_Mylast;
        v142 = (RVO::Vector2)v131;
        result = (RVO::Vector2)v131;
        if ( v131 )
          *v131 = _Val;
      }
      else
      {
        v120 = (char *)&_Val - (char *)Myfirst;
        v121 = p_orcaLines->_Myend;
        if ( Mylast == v121 && !(v121 - Mylast) )
        {
          v122 = Mylast - Myfirst;
          if ( v122 == 0xFFFFFFFFFFFFFFFi64 )
            std::_Xlength_error("vector<T> too long");
          v123 = v121 - Myfirst;
          if ( 0xFFFFFFFFFFFFFFFi64 - (v123 >> 1) >= v123 )
            v124 = (v123 >> 1) + v123;
          else
            v124 = 0i64;
          if ( v124 < v122 + 1 )
            v124 = v122 + 1;
          std::vector<RVO::Line>::_Reallocate(p_orcaLines, v124);
        }
        v125 = (float *)((char *)&p_orcaLines->_Myfirst->point + (v120 & 0xFFFFFFFFFFFFFFF0ui64));
        v126 = p_orcaLines->_Mylast;
        v142 = (RVO::Vector2)v126;
        result = (RVO::Vector2)v126;
        if ( v126 )
        {
          v126->point.x_ = *v125;
          v126->point.y_ = v125[1];
          v126->direction.x_ = v125[2];
          v126->direction.y_ = v125[3];
        }
      }
      ++p_orcaLines->_Mylast;
      ++v87;
      ++v88;
    }
    while ( v87 < v1->agentNeighbors_._Mylast - v1->agentNeighbors_._Myfirst );
  }
  v132 = RVO::linearProgram2(p_orcaLines, v1->maxSpeed_, &v1->prefVelocity_, 0, &v1->newVelocity_);
  if ( v132 >= p_orcaLines->_Mylast - p_orcaLines->_Myfirst )
  {
    v1->resolved_ = 1;
  }
  else
  {
    RVO::linearProgram3(p_orcaLines, v85, v132, v1->maxSpeed_, &v1->fallbackVelocity_);
    v1->resolved_ = 0;
  }
}

// File Line: 440
// RVA: 0xF90E0
char __fastcall RVO::Agent::insertAgentNeighbor(RVO::Agent *this, RVO::Obstacle *agent, float *rangeSq)
{
  RVO::Vector2 *v6; // rax
  float v7; // xmm6_4
  signed __int64 v8; // rdx
  unsigned __int64 v9; // rcx
  std::pair<float,RVO::Agent const *> *Myfirst; // r8
  float first; // eax
  std::pair<float,RVO::Agent const *> *v12; // rdx
  std::pair<float,RVO::Obstacle const *> _Val; // [rsp+20h] [rbp-28h] BYREF
  RVO::Vector2 result; // [rsp+50h] [rbp+8h] BYREF

  if ( this == (RVO::Agent *)agent )
    return 0;
  v6 = RVO::Vector2::operator-(&this->position_, &result, (RVO::Vector2 *)&agent[2]);
  v7 = (float)(v6->x_ * v6->x_) + (float)(v6->y_ * v6->y_);
  if ( v7 >= *rangeSq )
    return 0;
  if ( this->agentNeighbors_._Mylast - this->agentNeighbors_._Myfirst < this->maxNeighbors_ )
  {
    _Val.first = (float)(v6->x_ * v6->x_) + (float)(v6->y_ * v6->y_);
    _Val.second = agent;
    std::vector<std::pair<float,RVO::Obstacle const *>>::push_back(
      (std::vector<std::pair<float,RVO::Obstacle const *>> *)this,
      &_Val);
  }
  v8 = this->agentNeighbors_._Mylast - this->agentNeighbors_._Myfirst - 1;
  if ( this->agentNeighbors_._Mylast - this->agentNeighbors_._Myfirst != 1 )
  {
    v9 = v8;
    do
    {
      Myfirst = this->agentNeighbors_._Myfirst;
      if ( v7 >= this->agentNeighbors_._Myfirst[v9 - 1].first )
        break;
      first = Myfirst[--v9].first;
      Myfirst[v9 + 1].first = first;
      Myfirst[v9 + 1].second = Myfirst[v9].second;
      --v8;
    }
    while ( v8 );
  }
  v12 = &this->agentNeighbors_._Myfirst[v8];
  v12->first = v7;
  v12->second = (RVO::Agent *)agent;
  if ( this->agentNeighbors_._Mylast - this->agentNeighbors_._Myfirst == this->maxNeighbors_ )
    *rangeSq = this->agentNeighbors_._Mylast[-1].first;
  return 1;
}

// File Line: 473
// RVA: 0xF9200
bool __fastcall RVO::Agent::insertObstacleNeighbor(RVO::Agent *this, RVO::Obstacle *obstacle, float rangeSq)
{
  float v5; // xmm0_4
  signed __int64 v6; // rdx
  __int64 v7; // rcx
  std::pair<float,RVO::Obstacle const *> *Myfirst; // r8
  float first; // eax
  bool result; // al
  std::pair<float,RVO::Obstacle const *> *v11; // rdx
  std::pair<float,RVO::Obstacle const *> _Val; // [rsp+20h] [rbp-38h] BYREF

  v5 = RVO::distSqPointLineSegment(&obstacle->point_, &obstacle->nextObstacle->point_, &this->position_);
  if ( v5 >= rangeSq )
    return 0;
  _Val.first = v5;
  _Val.second = obstacle;
  std::vector<std::pair<float,RVO::Obstacle const *>>::push_back(&this->obstacleNeighbors_, &_Val);
  v6 = this->obstacleNeighbors_._Mylast - this->obstacleNeighbors_._Myfirst - 1;
  if ( this->obstacleNeighbors_._Mylast - this->obstacleNeighbors_._Myfirst != 1 )
  {
    v7 = v6;
    do
    {
      Myfirst = this->obstacleNeighbors_._Myfirst;
      if ( v5 >= Myfirst[v7 - 1].first )
        break;
      first = Myfirst[--v7].first;
      Myfirst[v7 + 1].first = first;
      Myfirst[v7 + 1].second = Myfirst[v7].second;
      --v6;
    }
    while ( v6 );
  }
  result = 1;
  v11 = &this->obstacleNeighbors_._Myfirst[v6];
  v11->first = v5;
  v11->second = obstacle;
  return result;
}

// File Line: 505
// RVA: 0xF92D0
char __fastcall RVO::linearProgram1(
        std::vector<RVO::Line> *lines,
        unsigned __int64 lineNo,
        float radius,
        RVO::Vector2 *optVelocity,
        bool directionOpt,
        RVO::Vector2 *result)
{
  RVO::Line *Myfirst; // rdi
  RVO::Line *v9; // rbp
  __m128 y_low; // xmm3
  __m128 v11; // xmm4
  unsigned __int64 v13; // rbx
  float v14; // xmm9_4
  float v15; // xmm8_4
  float v16; // xmm9_4
  float x; // xmm12_4
  float y; // xmm13_4
  float v19; // xmm6_4
  float v20; // xmm7_4
  float v21; // xmm10_4
  RVO::Vector2 *v22; // rax
  float v23; // xmm7_4
  float v24; // xmm7_4
  RVO::Vector2 *p_direction; // r8
  float v26; // xmm1_4
  RVO::Vector2 *v27; // rax
  RVO::Vector2 *v28; // rax
  RVO::Vector2 v29; // rcx
  RVO::Vector2 v30; // [rsp+F0h] [rbp+8h] BYREF
  RVO::Vector2 v31; // [rsp+F8h] [rbp+10h] BYREF

  Myfirst = lines->_Myfirst;
  v9 = &lines->_Myfirst[lineNo];
  y_low = (__m128)LODWORD(v9->direction.y_);
  y_low.m128_f32[0] = (float)(y_low.m128_f32[0] * v9->point.y_) + (float)(v9->direction.x_ * v9->point.x_);
  v11 = y_low;
  v11.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(radius * radius))
                  - (float)((float)(v9->point.x_ * v9->point.x_) + (float)(v9->point.y_ * v9->point.y_));
  if ( v11.m128_f32[0] < 0.0 )
    return 0;
  v13 = 0i64;
  v14 = _mm_sqrt_ps(v11).m128_f32[0];
  v15 = COERCE_FLOAT(y_low.m128_i32[0] ^ _xmm[0]) - v14;
  v16 = v14 - y_low.m128_f32[0];
  if ( lineNo )
  {
    x = v9->direction.x_;
    y = v9->direction.y_;
    do
    {
      v19 = Myfirst->direction.y_;
      v20 = Myfirst->direction.x_;
      v21 = (float)(v19 * x) - (float)(v20 * y);
      v22 = RVO::Vector2::operator-(&v9->point, &v30, &Myfirst->point);
      v23 = (float)(v20 * v22->y_) - (float)(v19 * v22->x_);
      if ( COERCE_FLOAT(LODWORD(v21) & _xmm) > 0.0000099999997 )
      {
        v24 = v23 / v21;
        if ( v21 < 0.0 )
        {
          if ( v15 <= v24 )
            v15 = v24;
        }
        else if ( v16 >= v24 )
        {
          v16 = v24;
        }
        if ( v15 > v16 )
          return 0;
      }
      else if ( v23 < 0.0 )
      {
        return 0;
      }
      ++v13;
      ++Myfirst;
    }
    while ( v13 < lineNo );
  }
  if ( directionOpt )
  {
    p_direction = &v9->direction;
    if ( (float)((float)(v9->direction.y_ * optVelocity->y_) + (float)(optVelocity->x_ * v9->direction.x_)) <= 0.0 )
      v26 = v15;
    else
      v26 = v16;
  }
  else
  {
    v27 = RVO::Vector2::operator-(optVelocity, &v30, &v9->point);
    v26 = (float)(v27->y_ * v9->direction.y_) + (float)(v27->x_ * v9->direction.x_);
    if ( v26 >= v15 )
    {
      if ( v26 > v16 )
        v26 = v16;
    }
    else
    {
      v26 = v15;
    }
    p_direction = &v9->direction;
  }
  v28 = RVO::operator*(&v30, v26, p_direction);
  v29 = *RVO::Vector2::operator+(&v9->point, &v31, v28);
  *result = v29;
  return 1;
}

// File Line: 593
// RVA: 0xF9580
unsigned __int64 __fastcall RVO::linearProgram2(
        std::vector<RVO::Line> *lines,
        float radius,
        RVO::Vector2 *optVelocity,
        bool directionOpt,
        RVO::Vector2 *result)
{
  RVO::Vector2 *v9; // rax
  RVO::Vector2 *v10; // rsi
  RVO::Vector2 *v11; // rax
  RVO::Vector2 *v12; // rax
  RVO::Line *Myfirst; // rcx
  unsigned __int64 v14; // rdi
  __int64 i; // r15
  RVO::Line *v16; // rbx
  RVO::Vector2 *v17; // rax
  float y; // xmm1_4
  unsigned __int64 v19; // rax
  RVO::Vector2 v20; // [rsp+30h] [rbp-58h] BYREF
  RVO::Vector2 v21; // [rsp+90h] [rbp+8h] BYREF

  if ( directionOpt )
  {
    v9 = RVO::Vector2::operator*(optVelocity, &v21, radius);
    v10 = result;
    *result = *v9;
  }
  else if ( (float)((float)(optVelocity->x_ * optVelocity->x_) + (float)(optVelocity->y_ * optVelocity->y_)) <= (float)(radius * radius) )
  {
    v10 = result;
    *result = *optVelocity;
  }
  else
  {
    v11 = RVO::normalize(&v21, optVelocity);
    v12 = RVO::Vector2::operator*(v11, &v20, radius);
    v10 = result;
    *result = *v12;
  }
  Myfirst = lines->_Myfirst;
  v14 = 0i64;
  if ( !(lines->_Mylast - lines->_Myfirst) )
    return lines->_Mylast - lines->_Myfirst;
  for ( i = 0i64; ; ++i )
  {
    v16 = &Myfirst[i];
    v17 = RVO::Vector2::operator-(&Myfirst[i].point, &v20, v10);
    if ( (float)((float)(v17->y_ * v16->direction.x_) - (float)(v16->direction.y_ * v17->x_)) > 0.0 )
    {
      y = v10->y_;
      v21.x_ = v10->x_;
      v21.y_ = y;
      if ( !RVO::linearProgram1(lines, v14, radius, optVelocity, directionOpt, v10) )
        break;
    }
    Myfirst = lines->_Myfirst;
    if ( ++v14 >= lines->_Mylast - lines->_Myfirst )
      return lines->_Mylast - lines->_Myfirst;
  }
  v19 = v14;
  *v10 = v21;
  return v19;
}

// File Line: 631
// RVA: 0xF9730
void __fastcall RVO::linearProgram3(
        std::vector<RVO::Line> *lines,
        unsigned __int64 numObstLines,
        unsigned __int64 beginLine,
        float radius,
        RVO::Vector2 *result)
{
  unsigned __int64 v5; // r15
  unsigned __int64 v6; // r14
  std::vector<RVO::Line> *v7; // r13
  float v8; // xmm6_4
  RVO::Line *Myfirst; // rbx
  unsigned __int64 v10; // rsi
  RVO::Vector2 *v11; // rax
  unsigned __int64 v12; // r13
  RVO::Line *Mylast; // rbx
  bool v14; // cf
  RVO::Line *v15; // r14
  RVO::Line *Myend; // rdi
  RVO::Line *v17; // r15
  RVO::Vector2 *v18; // rsi
  float v19; // xmm6_4
  RVO::Vector2 *v20; // rax
  RVO::Vector2 *v21; // rax
  RVO::Vector2 *v22; // rax
  RVO::Vector2 *v23; // rax
  RVO::Vector2 *v24; // rax
  signed __int64 v25; // rsi
  __int64 v26; // rbx
  unsigned __int64 v27; // rbx
  unsigned __int64 v28; // rdi
  unsigned __int64 v29; // rdi
  float *v30; // rsi
  __int64 v31; // rbx
  unsigned __int64 v32; // rbx
  unsigned __int64 v33; // rdi
  unsigned __int64 v34; // rdi
  float v35; // xmm1_4
  unsigned __int64 v36; // rdi
  unsigned __int64 v37; // rbx
  float *p_direction; // rsi
  RVO::Vector2 *v39; // rax
  RVO::Vector2 *v40; // rbx
  RVO::Vector2 *v41; // rax
  std::vector<RVO::Line> linesa; // [rsp+30h] [rbp-D0h] BYREF
  RVO::Vector2 v43; // [rsp+48h] [rbp-B8h] BYREF
  RVO::Vector2 v44; // [rsp+50h] [rbp-B0h]
  RVO::Vector2 optVelocity; // [rsp+58h] [rbp-A8h] BYREF
  unsigned __int64 v46; // [rsp+60h] [rbp-A0h]
  RVO::Vector2 v47; // [rsp+68h] [rbp-98h]
  RVO::Vector2 v48; // [rsp+70h] [rbp-90h]
  unsigned __int64 v49; // [rsp+78h] [rbp-88h]
  RVO::Line *v50; // [rsp+80h] [rbp-80h]
  RVO::Line *v51; // [rsp+88h] [rbp-78h]
  RVO::Vector2 v52; // [rsp+90h] [rbp-70h] BYREF
  RVO::Vector2 v53; // [rsp+98h] [rbp-68h] BYREF
  __int64 v54; // [rsp+A0h] [rbp-60h]
  RVO::Vector2 v55; // [rsp+A8h] [rbp-58h] BYREF
  RVO::Vector2 v56; // [rsp+B0h] [rbp-50h] BYREF
  RVO::Vector2 v57; // [rsp+B8h] [rbp-48h] BYREF
  RVO::Vector2 v58; // [rsp+C0h] [rbp-40h] BYREF
  RVO::Vector2 v59; // [rsp+C8h] [rbp-38h] BYREF
  RVO::Vector2 v60; // [rsp+D0h] [rbp-30h] BYREF
  RVO::Vector2 v61; // [rsp+D8h] [rbp-28h] BYREF
  RVO::Vector2 v62; // [rsp+E0h] [rbp-20h] BYREF
  RVO::Vector2 v63; // [rsp+E8h] [rbp-18h] BYREF
  unsigned __int64 v66; // [rsp+1A0h] [rbp+A0h]

  v54 = -2i64;
  v5 = beginLine;
  v46 = beginLine;
  v6 = numObstLines;
  v7 = lines;
  v8 = 0.0;
  Myfirst = lines->_Myfirst;
  if ( beginLine < lines->_Mylast - lines->_Myfirst )
  {
    v10 = 16 * beginLine;
    v66 = 16 * beginLine;
    do
    {
      v11 = RVO::Vector2::operator-((RVO::Vector2 *)((char *)&Myfirst->point + v10), &v58, result);
      if ( (float)((float)(v11->y_ * *(float *)((char *)&Myfirst->direction.x_ + v10))
                 - (float)(v11->x_ * *(float *)((char *)&Myfirst->direction.y_ + v10))) > v8 )
      {
        v12 = v6;
        memset(&linesa, 0, sizeof(linesa));
        std::vector<RVO::Line>::_Construct<std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<RVO::Line>>>>(
          &linesa,
          (std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<RVO::Line> > >)Myfirst,
          (std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<RVO::Line> > >)&Myfirst[v6]);
        v49 = v6;
        Mylast = linesa._Mylast;
        v14 = v6 < v5;
        v15 = linesa._Myfirst;
        if ( v14 )
        {
          Myend = linesa._Myend;
          while ( 1 )
          {
            v43 = 0i64;
            v44 = 0i64;
            v17 = &lines->_Myfirst[v12];
            v18 = (RVO::Vector2 *)((char *)&lines->_Myfirst->point + v10);
            v19 = (float)(v17->direction.y_ * v18[1].x_) - (float)(v17->direction.x_ * v18[1].y_);
            if ( COERCE_FLOAT(LODWORD(v19) & _xmm) > 0.0000099999997 )
              break;
            if ( (float)((float)(v17->direction.y_ * v18[1].y_) + (float)(v17->direction.x_ * v18[1].x_)) <= 0.0 )
            {
              v20 = RVO::Vector2::operator+(v18, &v53, &lines->_Myfirst[v12].point);
              v21 = RVO::operator*(&v61, 0.5, v20);
              goto LABEL_10;
            }
LABEL_36:
            ++v49;
            ++v12;
            v5 = v46;
            v10 = v66;
            if ( v49 >= v46 )
              goto LABEL_37;
          }
          v22 = RVO::Vector2::operator-(v18, &v63, &lines->_Myfirst[v12].point);
          v23 = RVO::operator*(
                  &v52,
                  (float)((float)(v22->y_ * v17->direction.x_) - (float)(v22->x_ * v17->direction.y_)) / v19,
                  v18 + 1);
          v21 = RVO::Vector2::operator+(v18, &v62, v23);
LABEL_10:
          v43 = *v21;
          v24 = RVO::Vector2::operator-(&v17->direction, &v56, v18 + 1);
          v44 = *RVO::normalize(&v60, v24);
          if ( &v43 >= (RVO::Vector2 *)Mylast || v15 > (RVO::Line *)&v43 )
          {
            if ( Mylast == Myend && !(Myend - Mylast) )
            {
              v31 = Mylast - v15;
              if ( v31 == 0xFFFFFFFFFFFFFFFi64 )
                std::_Xlength_error("vector<T> too long");
              v32 = v31 + 1;
              v33 = Myend - v15;
              if ( 0xFFFFFFFFFFFFFFFi64 - (v33 >> 1) >= v33 )
                v34 = (v33 >> 1) + v33;
              else
                v34 = 0i64;
              if ( v34 < v32 )
                v34 = v32;
              std::vector<RVO::Line>::_Reallocate(&linesa, v34);
              Myend = linesa._Myend;
              Mylast = linesa._Mylast;
              v15 = linesa._Myfirst;
            }
            v51 = Mylast;
            v50 = Mylast;
            if ( Mylast )
            {
              Mylast->point = v43;
              Mylast->direction = v44;
            }
          }
          else
          {
            v25 = (char *)&v43 - (char *)v15;
            if ( Mylast == Myend && !(Myend - Mylast) )
            {
              v26 = Mylast - v15;
              if ( v26 == 0xFFFFFFFFFFFFFFFi64 )
                std::_Xlength_error("vector<T> too long");
              v27 = v26 + 1;
              v28 = Myend - v15;
              if ( 0xFFFFFFFFFFFFFFFi64 - (v28 >> 1) >= v28 )
                v29 = (v28 >> 1) + v28;
              else
                v29 = 0i64;
              if ( v29 < v27 )
                v29 = v27;
              std::vector<RVO::Line>::_Reallocate(&linesa, v29);
              Myend = linesa._Myend;
              Mylast = linesa._Mylast;
              v15 = linesa._Myfirst;
            }
            v30 = (float *)((char *)&v15->point + (v25 & 0xFFFFFFFFFFFFFFF0ui64));
            v50 = Mylast;
            v51 = Mylast;
            if ( Mylast )
            {
              Mylast->point.x_ = *v30;
              Mylast->point.y_ = v30[1];
              Mylast->direction.x_ = v30[2];
              Mylast->direction.y_ = v30[3];
            }
          }
          linesa._Mylast = ++Mylast;
          goto LABEL_36;
        }
LABEL_37:
        v48 = *result;
        v7 = lines;
        v35 = *(float *)((char *)&lines->_Myfirst->direction.x_ + v10);
        LODWORD(optVelocity.x_) = *(_DWORD *)((char *)&lines->_Myfirst->direction.y_ + v10) ^ _xmm[0];
        optVelocity.y_ = v35;
        *result = *RVO::Vector2::operator*(&optVelocity, &v55, radius);
        v36 = 0i64;
        v37 = Mylast - v15;
        if ( v37 )
        {
          p_direction = (float *)&v15->direction;
          while ( 1 )
          {
            v39 = RVO::Vector2::operator-((RVO::Vector2 *)p_direction - 1, &v57, result);
            if ( (float)((float)(v39->y_ * *p_direction) - (float)(v39->x_ * p_direction[1])) > 0.0 )
            {
              v47 = *result;
              if ( !RVO::linearProgram1(&linesa, v36, radius, &optVelocity, 1, result) )
                break;
            }
            ++v36;
            p_direction += 4;
            if ( v36 >= v37 )
              goto LABEL_44;
          }
          *result = v47;
        }
        else
        {
LABEL_44:
          v36 = v37;
        }
        if ( v36 < v37 )
          *result = v48;
        v10 = v66;
        v40 = (RVO::Vector2 *)((char *)&lines->_Myfirst->point + v66);
        v41 = RVO::Vector2::operator-(v40, &v59, result);
        v8 = (float)(v40[1].x_ * v41->y_) - (float)(v41->x_ * v40[1].y_);
        if ( v15 )
        {
          operator delete[](v15);
          memset(&linesa, 0, sizeof(linesa));
        }
        v6 = numObstLines;
      }
      v46 = ++v5;
      v10 += 16i64;
      v66 = v10;
      Myfirst = v7->_Myfirst;
    }
    while ( v5 < v7->_Mylast - v7->_Myfirst );
  }
}

