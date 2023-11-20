// File Line: 91
// RVA: 0xF6320
void __fastcall RVO::Agent::~Agent(RVO::Agent *this)
{
  RVO::Agent *v1; // rbx
  RVO::Line *v2; // rcx
  std::pair<float,RVO::Obstacle const *> *v3; // rcx

  v1 = this;
  v2 = this->orcaLines_._Myfirst;
  if ( v2 )
  {
    operator delete[](v2);
    v1->orcaLines_._Myfirst = 0i64;
    v1->orcaLines_._Mylast = 0i64;
    v1->orcaLines_._Myend = 0i64;
  }
  v3 = v1->obstacleNeighbors_._Myfirst;
  if ( v3 )
  {
    operator delete[](v3);
    v1->obstacleNeighbors_._Myfirst = 0i64;
    v1->obstacleNeighbors_._Mylast = 0i64;
    v1->obstacleNeighbors_._Myend = 0i64;
  }
  if ( v1->agentNeighbors_._Myfirst )
  {
    operator delete[](v1->agentNeighbors_._Myfirst);
    v1->agentNeighbors_._Myfirst = 0i64;
    v1->agentNeighbors_._Mylast = 0i64;
    v1->agentNeighbors_._Myend = 0i64;
  }
}

// File Line: 96
// RVA: 0xF7BA0
void __fastcall RVO::Agent::computeNewVelocity(RVO::Agent *this)
{
  RVO::Agent *v1; // r15
  int v2; // edi
  std::vector<RVO::Line,std::allocator<RVO::Line> > *v3; // rsi
  float v4; // xmm14_4
  float v5; // xmm15_4
  RVO::Vector2 v6; // rcx
  int v7; // xmm13_4
  RVO::Vector2 *v8; // rbx
  float v9; // xmm7_4
  RVO::Obstacle *v10; // r12
  RVO::Obstacle *v11; // r13
  unsigned __int64 v12; // r15
  float v13; // xmm6_4
  float *v14; // rbx
  RVO::Vector2 *v15; // rax
  RVO::Vector2 *v16; // rax
  RVO::Vector2 *v17; // rax
  RVO::Vector2 *v18; // rax
  bool v19; // al
  __m128 v20; // xmm10
  float v21; // xmm11_4
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
  RVO::Vector2 *v41; // rax
  RVO::Vector2 v42; // rbx
  __m128 v43; // xmm0
  float v44; // xmm1_4
  float v45; // xmm6_4
  float v46; // xmm7_4
  float v47; // xmm2_4
  float v48; // xmm12_4
  float v49; // xmm8_4
  RVO::Vector2 *v50; // rax
  __m128 v51; // xmm0
  float v52; // xmm1_4
  RVO::Vector2 *v53; // rax
  __m128 v54; // xmm0
  float v55; // xmm1_4
  RVO::Vector2 *v56; // r14
  float v57; // xmm7_4
  float v58; // xmm8_4
  RVO::Vector2 *v59; // rax
  bool v60; // al
  RVO::Vector2 *v61; // rax
  RVO::Vector2 *v62; // rax
  RVO::Vector2 *v63; // rax
  float v64; // xmm6_4
  RVO::Vector2 *v65; // rax
  RVO::Vector2 *v66; // rax
  float v67; // xmm7_4
  RVO::Vector2 *v68; // rax
  float v69; // xmm10_4
  RVO::Vector2 *v70; // rax
  RVO::Vector2 *v71; // rax
  RVO::Vector2 *v72; // rax
  RVO::Vector2 *v73; // rax
  RVO::Vector2 *v74; // rdx
  RVO::Vector2 *v75; // rcx
  RVO::Vector2 *v76; // rax
  RVO::Vector2 *v77; // rax
  RVO::Vector2 *v78; // rax
  float v79; // xmm8_4
  float v80; // xmm6_4
  RVO::Vector2 *v81; // rax
  RVO::Vector2 *v82; // rax
  RVO::Vector2 *v83; // rax
  float v84; // xmm1_4
  RVO::Vector2 *v85; // rax
  RVO::Vector2 *v86; // rax
  RVO::Vector2 *v87; // rax
  unsigned __int64 v88; // r13
  float v89; // xmm11_4
  unsigned __int64 v90; // rdi
  __int64 v91; // r14
  RVO::Vector2 *v92; // rbx
  __m128 v93; // xmm7
  float v94; // xmm9_4
  __m128 v95; // xmm6
  float v96; // xmm8_4
  float v97; // xmm10_4
  RVO::Vector2 *v98; // rax
  __m128 v99; // xmm2
  __m128 v100; // xmm3
  float v101; // xmm1_4
  float v102; // xmm6_4
  RVO::Vector2 v103; // rax
  RVO::Vector2 *v104; // r8
  float v105; // xmm1_4
  RVO::Vector2 *v106; // rcx
  __m128 v107; // xmm0
  float v108; // xmm3_4
  float v109; // xmm1_4
  float v110; // xmm3_4
  float v111; // xmm0_4
  float v112; // xmm8_4
  RVO::Vector2 *v113; // rdx
  RVO::Vector2 *v114; // rcx
  RVO::Vector2 *v115; // rax
  RVO::Vector2 *v116; // rax
  float v117; // xmm7_4
  RVO::Vector2 *v118; // rax
  __m128 v119; // xmm1
  float v120; // xmm6_4
  RVO::Vector2 *v121; // rax
  RVO::Line *v122; // rcx
  RVO::Line *v123; // r8
  unsigned __int64 v124; // rbx
  RVO::Line *v125; // rdx
  signed __int64 v126; // rcx
  unsigned __int64 v127; // rdx
  unsigned __int64 v128; // rdx
  float *v129; // rbx
  RVO::Line *v130; // rcx
  RVO::Line *v131; // rdx
  signed __int64 v132; // rcx
  unsigned __int64 v133; // rdx
  unsigned __int64 v134; // rdx
  float *v135; // rax
  unsigned __int64 v136; // rax
  RVO::Line _Val; // [rsp+38h] [rbp-88h]
  RVO::Vector2 v138; // [rsp+48h] [rbp-78h]
  RVO::Vector2 v139; // [rsp+50h] [rbp-70h]
  RVO::Vector2 v140; // [rsp+58h] [rbp-68h]
  RVO::Vector2 v141; // [rsp+60h] [rbp-60h]
  RVO::Vector2 vector; // [rsp+68h] [rbp-58h]
  RVO::Vector2 v143; // [rsp+70h] [rbp-50h]
  RVO::Vector2 result; // [rsp+78h] [rbp-48h]
  RVO::Vector2 v145; // [rsp+80h] [rbp-40h]
  RVO::Vector2 v146; // [rsp+88h] [rbp-38h]
  RVO::Vector2 v147; // [rsp+90h] [rbp-30h]
  __int64 v148; // [rsp+98h] [rbp-28h]
  RVO::Vector2 v149; // [rsp+A0h] [rbp-20h]
  RVO::Vector2 v150; // [rsp+A8h] [rbp-18h]
  __int64 v151; // [rsp+B0h] [rbp-10h]
  RVO::Vector2 v152; // [rsp+B8h] [rbp-8h]
  RVO::Vector2 v153; // [rsp+C0h] [rbp+0h]
  RVO::Vector2 v154; // [rsp+C8h] [rbp+8h]
  RVO::Vector2 v155; // [rsp+D0h] [rbp+10h]
  __int64 v156; // [rsp+D8h] [rbp+18h]
  RVO::Vector2 v157; // [rsp+E0h] [rbp+20h]
  RVO::Vector2 v158; // [rsp+E8h] [rbp+28h]
  RVO::Vector2 v159; // [rsp+F0h] [rbp+30h]
  RVO::Vector2 v160; // [rsp+F8h] [rbp+38h]
  RVO::Vector2 v161; // [rsp+100h] [rbp+40h]
  RVO::Vector2 v162; // [rsp+108h] [rbp+48h]
  RVO::Vector2 v163; // [rsp+110h] [rbp+50h]
  RVO::Vector2 v164; // [rsp+118h] [rbp+58h]
  RVO::Vector2 v165; // [rsp+120h] [rbp+60h]
  RVO::Vector2 v166; // [rsp+128h] [rbp+68h]
  RVO::Vector2 v167; // [rsp+130h] [rbp+70h]
  RVO::Vector2 v168; // [rsp+138h] [rbp+78h]
  RVO::Vector2 v169; // [rsp+140h] [rbp+80h]
  RVO::Vector2 v170; // [rsp+148h] [rbp+88h]
  RVO::Vector2 v171; // [rsp+150h] [rbp+90h]
  RVO::Vector2 v172; // [rsp+158h] [rbp+98h]
  RVO::Vector2 v173; // [rsp+160h] [rbp+A0h]
  RVO::Vector2 v174; // [rsp+168h] [rbp+A8h]
  RVO::Vector2 v175; // [rsp+170h] [rbp+B0h]
  RVO::Vector2 v176; // [rsp+178h] [rbp+B8h]
  RVO::Vector2 v177; // [rsp+180h] [rbp+C0h]
  RVO::Vector2 v178; // [rsp+188h] [rbp+C8h]
  RVO::Vector2 v179; // [rsp+190h] [rbp+D0h]
  RVO::Vector2 v180; // [rsp+198h] [rbp+D8h]
  RVO::Vector2 v181; // [rsp+1A0h] [rbp+E0h]
  RVO::Vector2 v182; // [rsp+1A8h] [rbp+E8h]
  RVO::Vector2 v183; // [rsp+1B0h] [rbp+F0h]
  RVO::Vector2 v184; // [rsp+1B8h] [rbp+F8h]
  RVO::Vector2 v185; // [rsp+1C0h] [rbp+100h]
  RVO::Vector2 v186; // [rsp+1C8h] [rbp+108h]
  RVO::Vector2 v187; // [rsp+1D0h] [rbp+110h]
  RVO::Vector2 v188; // [rsp+1D8h] [rbp+118h]
  RVO::Vector2 v189; // [rsp+1E0h] [rbp+120h]
  RVO::Vector2 v190; // [rsp+1E8h] [rbp+128h]
  RVO::Vector2 v191; // [rsp+1F0h] [rbp+130h]
  RVO::Vector2 v192; // [rsp+1F8h] [rbp+138h]
  RVO::Vector2 v193; // [rsp+200h] [rbp+140h]
  RVO::Vector2 v194; // [rsp+208h] [rbp+148h]
  RVO::Vector2 v195; // [rsp+210h] [rbp+150h]
  RVO::Vector2 v196; // [rsp+218h] [rbp+158h]
  RVO::Vector2 v197; // [rsp+220h] [rbp+160h]
  __int64 v198; // [rsp+228h] [rbp+168h]
  RVO::Vector2 v199; // [rsp+230h] [rbp+170h]
  RVO::Vector2 v200; // [rsp+238h] [rbp+178h]
  RVO::Vector2 v201; // [rsp+240h] [rbp+180h]
  RVO::Vector2 v202; // [rsp+248h] [rbp+188h]
  RVO::Vector2 v203; // [rsp+250h] [rbp+190h]
  RVO::Vector2 v204; // [rsp+258h] [rbp+198h]
  RVO::Vector2 v205; // [rsp+350h] [rbp+290h]
  RVO::Vector2 v206; // [rsp+358h] [rbp+298h]
  RVO::Vector2 v207; // [rsp+360h] [rbp+2A0h]
  RVO::Vector2 v208; // [rsp+368h] [rbp+2A8h]

  v198 = -2i64;
  v1 = this;
  v2 = 0;
  v3 = &this->orcaLines_;
  this->orcaLines_._Mylast = this->orcaLines_._Myfirst;
  v4 = *(float *)&FLOAT_1_0;
  v5 = 1.0 / this->timeHorizonObst_;
  v6 = 0i64;
  v139 = 0i64;
  v7 = _xmm[0];
  if ( (_QWORD)((char *)v1->obstacleNeighbors_._Mylast - (char *)v1->obstacleNeighbors_._Myfirst) >> 4 )
  {
    v8 = &v1->position_;
    v9 = FLOAT_N0_0000099999997;
    while ( 1 )
    {
      v10 = v1->obstacleNeighbors_._Myfirst[*(_QWORD *)&v6].second;
      v11 = v10->nextObstacle;
      RVO::Vector2::operator-(&v10->point_, &result, v8);
      RVO::Vector2::operator-(&v11->point_, &vector, v8);
      v12 = 0i64;
      if ( (_QWORD)((char *)v3->_Mylast - (char *)v3->_Myfirst) >> 4 )
      {
        v13 = v5 * *(float *)(*(_QWORD *)&v205 + 112i64);
        v14 = (float *)&v3->_Myfirst->direction;
        while ( 1 )
        {
          v2 |= 3u;
          v15 = RVO::operator*(&v178, v5, &result);
          v16 = RVO::Vector2::operator-(v15, &v180, (RVO::Vector2 *)v14 - 1);
          v19 = 0;
          if ( (float)((float)((float)(v14[1] * v16->x_) - (float)(*v14 * v16->y_)) - v13) >= v9 )
          {
            v2 |= 0xCu;
            v17 = RVO::operator*(&v182, v5, &vector);
            v18 = RVO::Vector2::operator-(v17, &v184, (RVO::Vector2 *)v14 - 1);
            if ( (float)((float)((float)(v14[1] * v18->x_) - (float)(*v14 * v18->y_)) - v13) >= v9 )
              v19 = 1;
          }
          if ( v2 & 8 )
            v2 &= 0xFFFFFFF7;
          if ( v2 & 4 )
            v2 &= 0xFFFFFFFB;
          if ( v2 & 2 )
            v2 &= 0xFFFFFFFD;
          if ( v2 & 1 )
            v2 &= 0xFFFFFFFE;
          if ( v19 )
            break;
          ++v12;
          v14 += 4;
          if ( v12 >= (_QWORD)((char *)v3->_Mylast - (char *)v3->_Myfirst) >> 4 )
            goto LABEL_19;
        }
        v1 = (RVO::Agent *)v205;
        goto LABEL_115;
      }
LABEL_19:
      v20 = (__m128)LODWORD(result.y_);
      v22 = v20;
      v21 = result.x_;
      v22.m128_f32[0] = (float)(v20.m128_f32[0] * v20.m128_f32[0]) + (float)(v21 * v21);
      v23 = (__m128)LODWORD(vector.y_);
      v25 = v23;
      v24 = vector.x_;
      v25.m128_f32[0] = (float)(v23.m128_f32[0] * v23.m128_f32[0]) + (float)(v24 * v24);
      v1 = (RVO::Agent *)v205;
      v26 = *(float *)(*(_QWORD *)&v205 + 112i64);
      v27 = v26 * v26;
      RVO::Vector2::operator-(&v11->point_, &v141, &v10->point_);
      v28 = RVO::Vector2::operator-(&result, &v186);
      v29 = (float)((float)(v141.y_ * v28->y_) + (float)(v141.x_ * v28->x_))
          / (float)((float)(v141.y_ * v141.y_) + (float)(v141.x_ * v141.x_));
      v30 = RVO::operator*(&v188, v29, &v141);
      v31 = RVO::Vector2::operator-(&result, &v190);
      v32 = RVO::Vector2::operator-(v31, &v192, v30);
      v33 = (float)(v32->y_ * v32->y_) + (float)(v32->x_ * v32->x_);
      _Val.point = 0i64;
      _Val.direction = 0i64;
      if ( v29 < 0.0 && v22.m128_f32[0] <= v27 )
      {
        v7 = _xmm[0];
        if ( v10->isConvex_ )
        {
          v156 = 0i64;
          _Val.point = 0i64;
          LODWORD(v152.x_) = v20.m128_i32[0] ^ _xmm[0];
          v152.y_ = v21;
          _Val.direction = *RVO::normalize(&v194, &v152);
          std::vector<RVO::Line,std::allocator<RVO::Line>>::push_back(v3, &_Val);
        }
        goto LABEL_23;
      }
      if ( v29 <= 1.0 || v25.m128_f32[0] > v27 )
        break;
      if ( !v11->isConvex_ )
        goto LABEL_33;
      v7 = _xmm[0];
      if ( (float)((float)(v24 * v11->unitDir_.y_) - (float)(v23.m128_f32[0] * v11->unitDir_.x_)) >= 0.0 )
      {
        v148 = 0i64;
        _Val.point = 0i64;
        LODWORD(v149.x_) = v23.m128_i32[0] ^ _xmm[0];
        v149.y_ = v24;
        _Val.direction = *RVO::normalize(&v196, &v149);
        std::vector<RVO::Line,std::allocator<RVO::Line>>::push_back(v3, &_Val);
        v9 = FLOAT_N0_0000099999997;
        v4 = *(float *)&FLOAT_1_0;
        goto LABEL_115;
      }
LABEL_23:
      v9 = FLOAT_N0_0000099999997;
      v4 = *(float *)&FLOAT_1_0;
LABEL_115:
      v6 = (RVO::Vector2)(*(_QWORD *)&v139 + 1i64);
      v139 = v6;
      v8 = &v1->position_;
      if ( *(unsigned __int64 *)&v6 >= (_QWORD)((char *)v1->obstacleNeighbors_._Mylast
                                              - (char *)v1->obstacleNeighbors_._Myfirst) >> 4 )
        goto LABEL_116;
    }
    if ( v29 < 0.0 )
      goto LABEL_162;
    if ( v29 < 1.0 && v33 <= v27 )
    {
      v151 = 0i64;
      _Val.point = 0i64;
      _Val.direction = *RVO::Vector2::operator-(&v10->unitDir_, &v169);
      std::vector<RVO::Line,std::allocator<RVO::Line>>::push_back(v3, &_Val);
LABEL_33:
      v7 = _xmm[0];
      goto LABEL_23;
    }
    if ( v29 < 0.0 )
    {
LABEL_162:
      if ( v33 <= v27 )
      {
        if ( v10->isConvex_ )
        {
          v11 = v10;
          v34 = v22;
          v34.m128_f32[0] = v22.m128_f32[0] - v27;
          LODWORD(v35) = (unsigned __int128)_mm_sqrt_ps(v34);
          v36 = v21 * v26;
          v37 = v20.m128_f32[0] * v35;
          v38 = (float)(v20.m128_f32[0] * v35) + (float)(v21 * v26);
          v39 = v21 * v35;
          v40 = v20.m128_f32[0] * v26;
          v153.x_ = v39 - v40;
          v153.y_ = v38;
          v41 = RVO::Vector2::operator/(&v153, &v200, v22.m128_f32[0]);
          v42 = *v41;
          v138 = *v41;
          v145.x_ = v40 + v39;
          v145.y_ = v37 - v36;
          v208 = *RVO::Vector2::operator/(&v145, &v202, v22.m128_f32[0]);
          goto LABEL_48;
        }
        goto LABEL_33;
      }
    }
    if ( v29 <= 1.0 || v33 > v27 )
    {
      if ( v10->isConvex_ )
      {
        v51 = v22;
        v51.m128_f32[0] = v22.m128_f32[0] - v27;
        LODWORD(v52) = (unsigned __int128)_mm_sqrt_ps(v51);
        v157.x_ = (float)(v21 * v52) - (float)(v20.m128_f32[0] * v26);
        v157.y_ = (float)(v21 * v26) + (float)(v20.m128_f32[0] * v52);
        v53 = RVO::Vector2::operator/(&v157, &v203, v22.m128_f32[0]);
      }
      else
      {
        v53 = RVO::Vector2::operator-(&v10->unitDir_, &v173);
      }
      v42 = *v53;
      v138 = *v53;
      if ( v11->isConvex_ )
      {
        v54 = v25;
        v54.m128_f32[0] = v25.m128_f32[0] - v27;
        LODWORD(v55) = (unsigned __int128)_mm_sqrt_ps(v54);
        v143.x_ = (float)(v23.m128_f32[0] * v26) + (float)(v24 * v55);
        v143.y_ = (float)(v23.m128_f32[0] * v55) - (float)(v24 * v26);
        v208 = *RVO::Vector2::operator/(&v143, &v189, v25.m128_f32[0]);
      }
      else
      {
        v208 = v10->unitDir_;
      }
LABEL_48:
      v56 = (RVO::Vector2 *)v10->prevObstacle;
      LOBYTE(v206.x_) = 0;
      LOBYTE(v207.x_) = 0;
      v57 = v138.y_;
      v58 = v138.x_;
      v60 = 0;
      if ( v10->isConvex_ )
      {
        v2 |= 0x10u;
        v59 = RVO::Vector2::operator-(v56 + 4, &v175);
        if ( (float)((float)(v59->y_ * v58) - (float)(v59->x_ * v57)) >= 0.0 )
          v60 = 1;
      }
      if ( v2 & 0x10 )
        v2 &= 0xFFFFFFEF;
      if ( v60 )
      {
        v61 = RVO::Vector2::operator-(v56 + 4, &v197);
        v42 = *v61;
        v138 = *v61;
        LOBYTE(v206.x_) = 1;
        v57 = v138.y_;
        v58 = v138.x_;
      }
      if ( v11->isConvex_ && (float)((float)(v11->unitDir_.y_ * v208.x_) - (float)(v11->unitDir_.x_ * v208.y_)) <= 0.0 )
      {
        v208 = v11->unitDir_;
        LOBYTE(v207.x_) = 1;
      }
      v62 = RVO::Vector2::operator-(&v10->point_, &v177, &v1->position_);
      RVO::operator*(&v139, v5, v62);
      v63 = RVO::Vector2::operator-(&v11->point_, &v191, &v1->position_);
      RVO::operator*(&v143, v5, v63);
      RVO::Vector2::operator-(&v143, &v141, &v139);
      if ( v10 == v11 )
      {
        v64 = FLOAT_0_5;
      }
      else
      {
        v2 |= 0x20u;
        v65 = RVO::Vector2::operator-(&v1->velocity_, &v179, &v139);
        v64 = (float)((float)(v141.y_ * v65->y_) + (float)(v141.x_ * v65->x_))
            / (float)((float)(v141.y_ * v141.y_) + (float)(v141.x_ * v141.x_));
      }
      if ( v2 & 0x20 )
        v2 &= 0xFFFFFFDF;
      v66 = RVO::Vector2::operator-(&v1->velocity_, &v201, &v139);
      v67 = (float)(v57 * v66->y_) + (float)(v58 * v66->x_);
      v68 = RVO::Vector2::operator-(&v1->velocity_, &v181, &v143);
      v69 = (float)(v208.y_ * v68->y_) + (float)(v208.x_ * v68->x_);
      if ( (v64 >= 0.0 || v67 >= 0.0) && (v10 != v11 || v67 >= 0.0 || v69 >= 0.0) )
      {
        v4 = *(float *)&FLOAT_1_0;
        if ( v64 > 1.0 && v69 < 0.0 )
        {
          v72 = RVO::Vector2::operator-(&v1->velocity_, &v185, &v143);
          RVO::normalize(&vector, v72);
          v154.x_ = vector.y_;
          v7 = _xmm[0];
          LODWORD(v154.y_) = LODWORD(vector.x_) ^ _xmm[0];
          _Val.direction = v154;
          v73 = RVO::operator*(&v195, v26 * v5, &vector);
          v74 = &v187;
          goto LABEL_73;
        }
        if ( v64 < 0.0 || v64 > 1.0 || v10 == v11 )
        {
          v79 = FInf._Float;
        }
        else
        {
          v2 |= 0x1C0u;
          v76 = RVO::operator*(&v170, v64, &v141);
          v77 = RVO::Vector2::operator+(&v139, &v172, v76);
          v78 = RVO::Vector2::operator-(&v1->velocity_, &v174, v77);
          v79 = (float)(v78->y_ * v78->y_) + (float)(v78->x_ * v78->x_);
        }
        if ( _bittest(&v2, 8u) )
          v2 &= 0xFFFFFEFF;
        if ( (v2 & 0x80u) != 0 )
          v2 &= 0xFFFFFF7F;
        if ( v2 & 0x40 )
          v2 &= 0xFFFFFFBF;
        if ( v67 >= 0.0 )
        {
          v2 |= 0xE00u;
          v81 = RVO::operator*(&v176, v67, &v138);
          v82 = RVO::Vector2::operator+(&v139, &result, v81);
          v83 = RVO::Vector2::operator-(&v1->velocity_, &v146, v82);
          v80 = (float)(v83->y_ * v83->y_) + (float)(v83->x_ * v83->x_);
        }
        else
        {
          v80 = FInf._Float;
        }
        if ( _bittest(&v2, 0xBu) )
          v2 &= 0xFFFFF7FF;
        if ( _bittest(&v2, 0xAu) )
          v2 &= 0xFFFFFBFF;
        if ( _bittest(&v2, 9u) )
          v2 &= 0xFFFFFDFF;
        if ( v69 >= 0.0 )
        {
          v2 |= 0x7000u;
          v85 = RVO::operator*(&v158, v69, &v208);
          v86 = RVO::Vector2::operator+(&v143, &v167, v85);
          v87 = RVO::Vector2::operator-(&v1->velocity_, &v161, v86);
          v84 = (float)(v87->y_ * v87->y_) + (float)(v87->x_ * v87->x_);
        }
        else
        {
          v84 = FInf._Float;
        }
        if ( _bittest(&v2, 0xEu) )
          v2 &= 0xFFFFBFFF;
        if ( _bittest(&v2, 0xDu) )
          v2 &= 0xFFFFDFFF;
        if ( _bittest(&v2, 0xCu) )
          v2 &= 0xFFFFEFFF;
        if ( v79 <= v80 && v79 <= v84 )
        {
          _Val.direction = *RVO::Vector2::operator-(&v10->unitDir_, &v165);
          v7 = _xmm[0];
          LODWORD(_Val.direction.x_) = LODWORD(_Val.direction.y_) ^ _xmm[0];
          LODWORD(_Val.direction.y_) ^= _xmm[0];
          v73 = RVO::operator*(&v163, v26 * v5, &_Val.direction);
          v74 = &v159;
          v75 = &v139;
          goto LABEL_74;
        }
        if ( v80 > v84 )
        {
          if ( LOBYTE(v207.x_) )
          {
            v7 = _xmm[0];
          }
          else
          {
            _Val.direction = *RVO::Vector2::operator-(&v208, &v164);
            v7 = _xmm[0];
            LODWORD(v140.x_) = LODWORD(_Val.direction.y_) ^ _xmm[0];
            v140.y_ = _Val.direction.x_;
            v73 = RVO::operator*(&v166, v26 * v5, &v140);
            v74 = &v168;
LABEL_73:
            v75 = &v143;
LABEL_74:
            _Val.point = *RVO::Vector2::operator+(v75, v74, v73);
            std::vector<RVO::Line,std::allocator<RVO::Line>>::push_back(v3, &_Val);
          }
        }
        else
        {
          v7 = _xmm[0];
          if ( !LOBYTE(v206.x_) )
          {
            _Val.direction = v42;
            LODWORD(v138.x_) = LODWORD(v42.y_) ^ _xmm[0];
            v138.y_ = v42.x_;
            v73 = RVO::operator*(&v160, v26 * v5, &v138);
            v74 = &v162;
            v75 = &v139;
            goto LABEL_74;
          }
        }
        v9 = FLOAT_N0_0000099999997;
        goto LABEL_115;
      }
      v70 = RVO::Vector2::operator-(&v1->velocity_, &v193, &v139);
      RVO::normalize(&v140, v70);
      v150.x_ = v140.y_;
      v7 = _xmm[0];
      LODWORD(v150.y_) = LODWORD(v140.x_) ^ _xmm[0];
      _Val.direction = v150;
      v71 = RVO::operator*(&v183, v26 * v5, &v140);
      _Val.point = *RVO::Vector2::operator+(&v139, &v199, v71);
      std::vector<RVO::Line,std::allocator<RVO::Line>>::push_back(v3, &_Val);
      goto LABEL_23;
    }
    if ( v11->isConvex_ )
    {
      v10 = v11;
      v43 = v25;
      v43.m128_f32[0] = v25.m128_f32[0] - v27;
      LODWORD(v44) = (unsigned __int128)_mm_sqrt_ps(v43);
      v45 = v24 * v26;
      v46 = v23.m128_f32[0] * v44;
      v47 = (float)(v23.m128_f32[0] * v44) + (float)(v24 * v26);
      v48 = v24 * v44;
      v49 = v23.m128_f32[0] * v26;
      v155.x_ = v48 - v49;
      v155.y_ = v47;
      v50 = RVO::Vector2::operator/(&v155, &v204, v25.m128_f32[0]);
      v42 = *v50;
      v138 = *v50;
      v147.x_ = v49 + v48;
      v147.y_ = v46 - v45;
      v208 = *RVO::Vector2::operator/(&v147, &v171, v25.m128_f32[0]);
      goto LABEL_48;
    }
    goto LABEL_33;
  }
LABEL_116:
  v88 = (_QWORD)((char *)v3->_Mylast - (char *)v3->_Myfirst) >> 4;
  v89 = v4 / v1->timeHorizon_;
  v90 = 0i64;
  if ( (_QWORD)((char *)v1->agentNeighbors_._Mylast - (char *)v1->agentNeighbors_._Myfirst) >> 4 )
  {
    v91 = 0i64;
    do
    {
      v92 = (RVO::Vector2 *)v1->agentNeighbors_._Myfirst[v91].second;
      RVO::Vector2::operator-(v92 + 12, &v206, &v1->position_);
      RVO::Vector2::operator-(&v1->velocity_, &v205, v92 + 17);
      v93 = (__m128)LODWORD(v206.y_);
      v95 = v93;
      v94 = v206.x_;
      v95.m128_f32[0] = (float)(v93.m128_f32[0] * v93.m128_f32[0]) + (float)(v94 * v94);
      v96 = v92[14].x_ + v1->radius_;
      v97 = v96 * v96;
      _Val.point = 0i64;
      if ( v95.m128_f32[0] <= (float)(v96 * v96) )
      {
        v117 = v4 / v1->sim_->timeStep_;
        v118 = RVO::operator*(&v165, v117, &v206);
        RVO::Vector2::operator-(&v205, &v141, v118);
        v119 = (__m128)LODWORD(v141.y_);
        v119.m128_f32[0] = (float)(v119.m128_f32[0] * v119.m128_f32[0]) + (float)(v141.x_ * v141.x_);
        LODWORD(v120) = (unsigned __int128)_mm_sqrt_ps(v119);
        RVO::Vector2::operator/(&v141, &vector, v120);
        _Val.direction.x_ = vector.y_;
        LODWORD(_Val.direction.y_) = LODWORD(vector.x_) ^ v7;
        v103 = _Val.direction;
        v104 = &vector;
        v105 = (float)(v117 * v96) - v120;
        v106 = &v161;
      }
      else
      {
        v98 = RVO::operator*(&v168, v89, &v206);
        RVO::Vector2::operator-(&v205, &v207, v98);
        v99 = (__m128)LODWORD(v207.y_);
        v100 = v99;
        v100.m128_f32[0] = (float)(v99.m128_f32[0] * v99.m128_f32[0]) + (float)(v207.x_ * v207.x_);
        v101 = (float)(v207.y_ * v93.m128_f32[0]) + (float)(v207.x_ * v94);
        if ( v101 >= 0.0 || (float)(v101 * v101) <= (float)(v100.m128_f32[0] * v97) )
        {
          v107 = v95;
          v107.m128_f32[0] = v95.m128_f32[0] - v97;
          LODWORD(v108) = (unsigned __int128)_mm_sqrt_ps(v107);
          v109 = v108 * v94;
          v110 = v108 * v93.m128_f32[0];
          v111 = v96 * v93.m128_f32[0];
          v112 = v96 * v94;
          if ( (float)((float)(v207.y_ * v94) - (float)(v207.x_ * v93.m128_f32[0])) <= 0.0 )
          {
            v138.x_ = v109 + v111;
            v138.y_ = v110 - v112;
            v114 = RVO::Vector2::operator-(&v138, &v162);
            v113 = &v160;
          }
          else
          {
            v140.x_ = v109 - v111;
            v140.y_ = v110 + v112;
            v113 = &v164;
            v114 = &v140;
          }
          _Val.direction = *RVO::Vector2::operator/(v114, v113, v95.m128_f32[0]);
          v115 = RVO::operator*(
                   &v159,
                   (float)(v205.y_ * _Val.direction.y_) + (float)(v205.x_ * _Val.direction.x_),
                   &_Val.direction);
          v116 = RVO::Vector2::operator-(v115, &v163, &v205);
          goto LABEL_128;
        }
        LODWORD(v102) = (unsigned __int128)_mm_sqrt_ps(v100);
        RVO::Vector2::operator/(&v207, &v208, v102);
        v139.x_ = v208.y_;
        LODWORD(v139.y_) = LODWORD(v208.x_) ^ v7;
        v103 = v139;
        v104 = &v208;
        v105 = (float)(v96 * v89) - v102;
        v106 = &v166;
      }
      _Val.direction = v103;
      v116 = RVO::operator*(v106, v105, v104);
LABEL_128:
      v140 = *v116;
      v121 = RVO::operator*(&v167, 0.5, &v140);
      _Val.point = *RVO::Vector2::operator+(&v1->velocity_, &v158, v121);
      v122 = v3->_Mylast;
      if ( &_Val >= v122 || (v123 = v3->_Myfirst, v3->_Myfirst > &_Val) )
      {
        v131 = v3->_Myend;
        if ( v122 == v131 && (unsigned __int64)(v131 - v122) < 1 )
        {
          v132 = v122 - v3->_Myfirst;
          if ( (unsigned __int64)(0xFFFFFFFFFFFFFFFi64 - v132) < 1 )
            std::_Xlength_error("vector<T> too long");
          v133 = v131 - v3->_Myfirst;
          if ( 0xFFFFFFFFFFFFFFFi64 - (v133 >> 1) >= v133 )
            v134 = (v133 >> 1) + v133;
          else
            v134 = 0i64;
          if ( v134 < v132 + 1 )
            v134 = v132 + 1;
          std::vector<RVO::Line,std::allocator<RVO::Line>>::_Reallocate(v3, v134);
        }
        v135 = (float *)&v3->_Mylast->point;
        v146 = (RVO::Vector2)v135;
        result = (RVO::Vector2)v135;
        if ( v135 )
        {
          *v135 = _Val.point.x_;
          v135[1] = _Val.point.y_;
          v135[2] = _Val.direction.x_;
          v135[3] = _Val.direction.y_;
        }
      }
      else
      {
        v124 = (char *)&_Val - (char *)v123;
        v125 = v3->_Myend;
        if ( v122 == v125 && (unsigned __int64)(v125 - v122) < 1 )
        {
          v126 = v122 - v123;
          if ( (unsigned __int64)(0xFFFFFFFFFFFFFFFi64 - v126) < 1 )
            std::_Xlength_error("vector<T> too long");
          v127 = v125 - v123;
          if ( 0xFFFFFFFFFFFFFFFi64 - (v127 >> 1) >= v127 )
            v128 = (v127 >> 1) + v127;
          else
            v128 = 0i64;
          if ( v128 < v126 + 1 )
            v128 = v126 + 1;
          std::vector<RVO::Line,std::allocator<RVO::Line>>::_Reallocate(v3, v128);
        }
        v129 = (float *)((char *)&v3->_Myfirst->point + (v124 & 0xFFFFFFFFFFFFFFF0ui64));
        v130 = v3->_Mylast;
        v146 = (RVO::Vector2)v130;
        result = (RVO::Vector2)v130;
        if ( v130 )
        {
          v130->point.x_ = *v129;
          v130->point.y_ = v129[1];
          v130->direction.x_ = v129[2];
          v130->direction.y_ = v129[3];
        }
      }
      ++v3->_Mylast;
      ++v90;
      ++v91;
    }
    while ( v90 < (_QWORD)((char *)v1->agentNeighbors_._Mylast - (char *)v1->agentNeighbors_._Myfirst) >> 4 );
  }
  v136 = RVO::linearProgram2(v3, v1->maxSpeed_, &v1->prefVelocity_, 0, &v1->newVelocity_);
  if ( v136 >= (_QWORD)((char *)v3->_Mylast - (char *)v3->_Myfirst) >> 4 )
  {
    v1->resolved_ = 1;
  }
  else
  {
    RVO::linearProgram3(v3, v88, v136, v1->maxSpeed_, &v1->fallbackVelocity_);
    v1->resolved_ = 0;
  }
}

// File Line: 440
// RVA: 0xF90E0
char __fastcall RVO::Agent::insertAgentNeighbor(RVO::Agent *this, RVO::Agent *agent, float *rangeSq)
{
  float *v3; // rsi
  RVO::Obstacle *v4; // rdi
  std::vector<std::pair<float,RVO::Obstacle const *>,std::allocator<std::pair<float,RVO::Obstacle const *> > > *v5; // rbx
  RVO::Vector2 *v6; // rax
  float v7; // xmm6_4
  signed __int64 v8; // rdx
  signed __int64 v9; // rcx
  std::pair<float,RVO::Obstacle const *> *v10; // r8
  float v11; // eax
  signed __int64 v12; // rdx
  std::pair<float,RVO::Obstacle const *> _Val; // [rsp+20h] [rbp-28h]
  RVO::Vector2 result; // [rsp+50h] [rbp+8h]

  v3 = rangeSq;
  v4 = (RVO::Obstacle *)agent;
  v5 = (std::vector<std::pair<float,RVO::Obstacle const *>,std::allocator<std::pair<float,RVO::Obstacle const *> > > *)this;
  if ( this == agent )
    return 0;
  v6 = RVO::Vector2::operator-(&this->position_, &result, &agent->position_);
  v7 = (float)(v6->x_ * v6->x_) + (float)(v6->y_ * v6->y_);
  if ( v7 >= *v3 )
    return 0;
  if ( (std::pair<float,RVO::Obstacle const *> *)((_QWORD)((char *)v5->_Mylast - (char *)v5->_Myfirst) >> 4) < v5[1]._Myfirst )
  {
    _Val.first = (float)(v6->x_ * v6->x_) + (float)(v6->y_ * v6->y_);
    _Val.second = v4;
    std::vector<std::pair<float,RVO::Obstacle const *>,std::allocator<std::pair<float,RVO::Obstacle const *>>>::push_back(
      v5,
      &_Val);
  }
  v8 = ((_QWORD)((char *)v5->_Mylast - (char *)v5->_Myfirst) >> 4) - 1i64;
  if ( (_QWORD)((char *)v5->_Mylast - (char *)v5->_Myfirst) >> 4 != 1i64 )
  {
    v9 = v8;
    do
    {
      v10 = v5->_Myfirst;
      if ( v7 >= v5->_Myfirst[v9 - 1].first )
        break;
      v11 = v10[v9 - 1].first;
      --v9;
      v10[v9 + 1].first = v11;
      v10[v9 + 1].second = v10[v9].second;
      --v8;
    }
    while ( v8 );
  }
  v12 = (signed __int64)&v5->_Myfirst[v8];
  *(float *)v12 = v7;
  *(_QWORD *)(v12 + 8) = v4;
  if ( (std::pair<float,RVO::Obstacle const *> *)((_QWORD)((char *)v5->_Mylast - (char *)v5->_Myfirst) >> 4) == v5[1]._Myfirst )
    *v3 = v5->_Mylast[-1].first;
  return 1;
}

// File Line: 473
// RVA: 0xF9200
char __fastcall RVO::Agent::insertObstacleNeighbor(RVO::Agent *this, RVO::Obstacle *obstacle, float rangeSq)
{
  RVO::Obstacle *v3; // rdi
  RVO::Agent *v4; // rbx
  float v5; // xmm0_4
  signed __int64 v6; // rdx
  signed __int64 v7; // rcx
  std::pair<float,RVO::Obstacle const *> *v8; // r8
  float v9; // eax
  char result; // al
  signed __int64 v11; // rdx
  std::pair<float,RVO::Obstacle const *> _Val; // [rsp+20h] [rbp-38h]

  v3 = obstacle;
  v4 = this;
  v5 = RVO::distSqPointLineSegment(&obstacle->point_, &obstacle->nextObstacle->point_, &this->position_);
  if ( v5 >= rangeSq )
    return 0;
  _Val.first = v5;
  _Val.second = v3;
  std::vector<std::pair<float,RVO::Obstacle const *>,std::allocator<std::pair<float,RVO::Obstacle const *>>>::push_back(
    &v4->obstacleNeighbors_,
    &_Val);
  v6 = ((_QWORD)((char *)v4->obstacleNeighbors_._Mylast - (char *)v4->obstacleNeighbors_._Myfirst) >> 4) - 1i64;
  if ( (_QWORD)((char *)v4->obstacleNeighbors_._Mylast - (char *)v4->obstacleNeighbors_._Myfirst) >> 4 != 1i64 )
  {
    v7 = v6;
    do
    {
      v8 = v4->obstacleNeighbors_._Myfirst;
      if ( v5 >= v8[v7 - 1].first )
        break;
      v9 = v8[v7 - 1].first;
      --v7;
      v8[v7 + 1].first = v9;
      v8[v7 + 1].second = v8[v7].second;
      --v6;
    }
    while ( v6 );
  }
  result = 1;
  v11 = (signed __int64)&v4->obstacleNeighbors_._Myfirst[v6];
  *(float *)v11 = v5;
  *(_QWORD *)(v11 + 8) = v3;
  return result;
}

// File Line: 505
// RVA: 0xF92D0
char __fastcall RVO::linearProgram1(std::vector<RVO::Line,std::allocator<RVO::Line> > *lines, unsigned __int64 lineNo, float radius, RVO::Vector2 *optVelocity, bool directionOpt, RVO::Vector2 *result)
{
  RVO::Line *v6; // rdi
  RVO::Vector2 *v7; // r15
  unsigned __int64 v8; // r14
  RVO::Line *v9; // rbp
  __m128 v10; // xmm3
  __m128 v11; // xmm4
  unsigned __int64 v13; // rbx
  float v14; // xmm9_4
  float v15; // xmm8_4
  float v16; // xmm9_4
  float v17; // xmm12_4
  float v18; // xmm13_4
  float v19; // xmm6_4
  float v20; // xmm7_4
  float v21; // xmm10_4
  RVO::Vector2 *v22; // rax
  float v23; // xmm7_4
  float v24; // xmm7_4
  RVO::Vector2 *v25; // r8
  float v26; // xmm1_4
  RVO::Vector2 *v27; // rax
  RVO::Vector2 *v28; // rax
  RVO::Vector2 v29; // rcx
  RVO::Vector2 v30; // [rsp+F0h] [rbp+8h]
  RVO::Vector2 v31; // [rsp+F8h] [rbp+10h]

  v6 = lines->_Myfirst;
  v7 = optVelocity;
  v8 = lineNo;
  v9 = &lines->_Myfirst[lineNo];
  v10 = (__m128)LODWORD(v9->direction.y_);
  v10.m128_f32[0] = (float)(v10.m128_f32[0] * v9->point.y_) + (float)(v9->direction.x_ * v9->point.x_);
  v11 = v10;
  v11.m128_f32[0] = (float)((float)(v10.m128_f32[0] * v10.m128_f32[0]) + (float)(radius * radius))
                  - (float)((float)(v9->point.x_ * v9->point.x_) + (float)(v9->point.y_ * v9->point.y_));
  if ( v11.m128_f32[0] < 0.0 )
    return 0;
  v13 = 0i64;
  LODWORD(v14) = (unsigned __int128)_mm_sqrt_ps(v11);
  v15 = COERCE_FLOAT(v10.m128_i32[0] ^ _xmm[0]) - v14;
  v16 = v14 - v10.m128_f32[0];
  if ( lineNo )
  {
    v17 = v9->direction.x_;
    v18 = v9->direction.y_;
    do
    {
      v19 = v6->direction.y_;
      v20 = v6->direction.x_;
      v21 = (float)(v6->direction.y_ * v17) - (float)(v6->direction.x_ * v18);
      v22 = RVO::Vector2::operator-(&v9->point, &v30, &v6->point);
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
      ++v6;
    }
    while ( v13 < v8 );
  }
  if ( directionOpt )
  {
    v25 = &v9->direction;
    if ( (float)((float)(v9->direction.y_ * v7->y_) + (float)(v7->x_ * v9->direction.x_)) <= 0.0 )
      v26 = v15;
    else
      v26 = v16;
  }
  else
  {
    v27 = RVO::Vector2::operator-(v7, &v30, &v9->point);
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
    v25 = &v9->direction;
  }
  v28 = RVO::operator*(&v30, v26, v25);
  v29 = *RVO::Vector2::operator+(&v9->point, &v31, v28);
  *result = v29;
  return 1;
}

// File Line: 593
// RVA: 0xF9580
unsigned __int64 __fastcall RVO::linearProgram2(std::vector<RVO::Line,std::allocator<RVO::Line> > *lines, float radius, RVO::Vector2 *optVelocity, bool directionOpt, RVO::Vector2 *result)
{
  bool v5; // r12
  RVO::Vector2 *v6; // rbp
  float v7; // xmm6_4
  std::vector<RVO::Line,std::allocator<RVO::Line> > *v8; // r14
  RVO::Vector2 *v9; // rax
  RVO::Vector2 *v10; // rsi
  RVO::Vector2 *v11; // rax
  RVO::Vector2 *v12; // rax
  RVO::Line *v13; // rcx
  unsigned __int64 v14; // rdi
  __int64 v15; // r15
  RVO::Line *v16; // rbx
  RVO::Vector2 *v17; // rax
  float v18; // xmm1_4
  unsigned __int64 v19; // rax
  RVO::Vector2 v20; // [rsp+30h] [rbp-58h]
  RVO::Vector2 v21; // [rsp+90h] [rbp+8h]

  v5 = directionOpt;
  v6 = optVelocity;
  v7 = radius;
  v8 = lines;
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
  v13 = v8->_Myfirst;
  v14 = 0i64;
  if ( !((_QWORD)((char *)v8->_Mylast - (char *)v8->_Myfirst) >> 4) )
    return (_QWORD)((char *)v8->_Mylast - (char *)v8->_Myfirst) >> 4;
  v15 = 0i64;
  while ( 1 )
  {
    v16 = &v13[v15];
    v17 = RVO::Vector2::operator-(&v13[v15].point, &v20, v10);
    if ( (float)((float)(v17->y_ * v16->direction.x_) - (float)(v16->direction.y_ * v17->x_)) > 0.0 )
    {
      v18 = v10->y_;
      v21.x_ = v10->x_;
      v21.y_ = v18;
      if ( !RVO::linearProgram1(v8, v14, v7, v6, v5, v10) )
        break;
    }
    v13 = v8->_Myfirst;
    ++v14;
    ++v15;
    if ( v14 >= (_QWORD)((char *)v8->_Mylast - (char *)v8->_Myfirst) >> 4 )
      return (_QWORD)((char *)v8->_Mylast - (char *)v8->_Myfirst) >> 4;
  }
  v19 = v14;
  *v10 = v21;
  return v19;
}

// File Line: 631
// RVA: 0xF9730
void __fastcall RVO::linearProgram3(std::vector<RVO::Line,std::allocator<RVO::Line> > *lines, unsigned __int64 numObstLines, unsigned __int64 beginLine, float radius, RVO::Vector2 *result)
{
  unsigned __int64 v5; // r15
  unsigned __int64 v6; // r14
  std::vector<RVO::Line,std::allocator<RVO::Line> > *v7; // r13
  float v8; // xmm6_4
  RVO::Line *v9; // rbx
  unsigned __int64 v10; // rsi
  RVO::Vector2 *v11; // rax
  signed __int64 v12; // r13
  RVO::Line *v13; // rbx
  bool v14; // cf
  RVO::Line *v15; // r14
  RVO::Line *v16; // rdi
  RVO::Vector2 *v17; // r15
  RVO::Vector2 *v18; // rsi
  float v19; // xmm6_4
  RVO::Vector2 *v20; // rax
  RVO::Vector2 *v21; // rax
  RVO::Vector2 *v22; // rax
  RVO::Vector2 *v23; // rax
  RVO::Vector2 *v24; // rax
  signed __int64 v25; // rsi
  signed __int64 v26; // rbx
  unsigned __int64 v27; // rbx
  unsigned __int64 v28; // rdi
  unsigned __int64 v29; // rdi
  float *v30; // rsi
  signed __int64 v31; // rbx
  unsigned __int64 v32; // rbx
  unsigned __int64 v33; // rdi
  unsigned __int64 v34; // rdi
  float v35; // xmm1_4
  unsigned __int64 v36; // rdi
  unsigned __int64 v37; // rbx
  float *v38; // rsi
  RVO::Vector2 *v39; // rax
  float *v40; // rbx
  RVO::Vector2 *v41; // rax
  std::vector<RVO::Line,std::allocator<RVO::Line> > linesa; // [rsp+30h] [rbp-D0h]
  RVO::Vector2 v43; // [rsp+48h] [rbp-B8h]
  RVO::Vector2 v44; // [rsp+50h] [rbp-B0h]
  RVO::Vector2 optVelocity; // [rsp+58h] [rbp-A8h]
  unsigned __int64 v46; // [rsp+60h] [rbp-A0h]
  RVO::Vector2 v47; // [rsp+68h] [rbp-98h]
  RVO::Vector2 v48; // [rsp+70h] [rbp-90h]
  unsigned __int64 v49; // [rsp+78h] [rbp-88h]
  RVO::Line *v50; // [rsp+80h] [rbp-80h]
  RVO::Line *v51; // [rsp+88h] [rbp-78h]
  RVO::Vector2 v52; // [rsp+90h] [rbp-70h]
  RVO::Vector2 v53; // [rsp+98h] [rbp-68h]
  __int64 v54; // [rsp+A0h] [rbp-60h]
  RVO::Vector2 v55; // [rsp+A8h] [rbp-58h]
  RVO::Vector2 v56; // [rsp+B0h] [rbp-50h]
  RVO::Vector2 v57; // [rsp+B8h] [rbp-48h]
  RVO::Vector2 v58; // [rsp+C0h] [rbp-40h]
  RVO::Vector2 v59; // [rsp+C8h] [rbp-38h]
  RVO::Vector2 v60; // [rsp+D0h] [rbp-30h]
  RVO::Vector2 v61; // [rsp+D8h] [rbp-28h]
  RVO::Vector2 v62; // [rsp+E0h] [rbp-20h]
  RVO::Vector2 v63; // [rsp+E8h] [rbp-18h]
  std::vector<RVO::Line,std::allocator<RVO::Line> > *v64; // [rsp+190h] [rbp+90h]
  unsigned __int64 v65; // [rsp+198h] [rbp+98h]
  unsigned __int64 v66; // [rsp+1A0h] [rbp+A0h]

  v65 = numObstLines;
  v64 = lines;
  v54 = -2i64;
  v5 = beginLine;
  v46 = beginLine;
  v6 = numObstLines;
  v7 = lines;
  v8 = 0.0;
  v9 = lines->_Myfirst;
  if ( beginLine < (_QWORD)((char *)lines->_Mylast - (char *)lines->_Myfirst) >> 4 )
  {
    v10 = 16 * beginLine;
    v66 = 16 * beginLine;
    do
    {
      v11 = RVO::Vector2::operator-((RVO::Vector2 *)((char *)&v9->point + v10), &v58, result);
      if ( (float)((float)(v11->y_ * *(float *)((char *)&v9->direction.x_ + v10))
                 - (float)(v11->x_ * *(float *)((char *)&v9->direction.y_ + v10))) > v8 )
      {
        v12 = v6;
        linesa._Myfirst = 0i64;
        *(_OWORD *)&linesa._Mylast = 0ui64;
        std::vector<RVO::Line,std::allocator<RVO::Line>>::_Construct<std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<RVO::Line>>>>(
          &linesa,
          (std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<RVO::Line> > >)v9,
          (std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<RVO::Line> > >)&v9[v6]);
        v49 = v6;
        v13 = linesa._Mylast;
        v14 = v6 < v5;
        v15 = linesa._Myfirst;
        if ( v14 )
        {
          v16 = linesa._Myend;
          while ( 1 )
          {
            v43 = 0i64;
            v44 = 0i64;
            v17 = &v64->_Myfirst[v12].point;
            v18 = (RVO::Vector2 *)((char *)&v64->_Myfirst->point + v10);
            v19 = (float)(v17[1].y_ * v18[1].x_) - (float)(v17[1].x_ * v18[1].y_);
            if ( COERCE_FLOAT(LODWORD(v19) & _xmm) > 0.0000099999997 )
              break;
            if ( (float)((float)(v17[1].y_ * v18[1].y_) + (float)(v17[1].x_ * v18[1].x_)) <= 0.0 )
            {
              v20 = RVO::Vector2::operator+(v18, &v53, &v64->_Myfirst[v12].point);
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
          v22 = RVO::Vector2::operator-(v18, &v63, &v64->_Myfirst[v12].point);
          v23 = RVO::operator*(
                  &v52,
                  (float)((float)(v22->y_ * v17[1].x_) - (float)(v22->x_ * v17[1].y_)) / v19,
                  v18 + 1);
          v21 = RVO::Vector2::operator+(v18, &v62, v23);
LABEL_10:
          v43 = *v21;
          v24 = RVO::Vector2::operator-(v17 + 1, &v56, v18 + 1);
          v44 = *RVO::normalize(&v60, v24);
          if ( &v43 >= (RVO::Vector2 *)v13 || v15 > (RVO::Line *)&v43 )
          {
            if ( v13 == v16 && (unsigned __int64)(v16 - v13) < 1 )
            {
              v31 = v13 - v15;
              if ( (unsigned __int64)(0xFFFFFFFFFFFFFFFi64 - v31) < 1 )
                std::_Xlength_error("vector<T> too long");
              v32 = v31 + 1;
              v33 = v16 - v15;
              if ( 0xFFFFFFFFFFFFFFFi64 - (v33 >> 1) >= v33 )
                v34 = (v33 >> 1) + v33;
              else
                v34 = 0i64;
              if ( v34 < v32 )
                v34 = v32;
              std::vector<RVO::Line,std::allocator<RVO::Line>>::_Reallocate(&linesa, v34);
              v16 = linesa._Myend;
              v13 = linesa._Mylast;
              v15 = linesa._Myfirst;
            }
            v51 = v13;
            v50 = v13;
            if ( v13 )
            {
              v13->point = v43;
              v13->direction = v44;
            }
          }
          else
          {
            v25 = (char *)&v43 - (char *)v15;
            if ( v13 == v16 && (unsigned __int64)(v16 - v13) < 1 )
            {
              v26 = v13 - v15;
              if ( (unsigned __int64)(0xFFFFFFFFFFFFFFFi64 - v26) < 1 )
                std::_Xlength_error("vector<T> too long");
              v27 = v26 + 1;
              v28 = v16 - v15;
              if ( 0xFFFFFFFFFFFFFFFi64 - (v28 >> 1) >= v28 )
                v29 = (v28 >> 1) + v28;
              else
                v29 = 0i64;
              if ( v29 < v27 )
                v29 = v27;
              std::vector<RVO::Line,std::allocator<RVO::Line>>::_Reallocate(&linesa, v29);
              v16 = linesa._Myend;
              v13 = linesa._Mylast;
              v15 = linesa._Myfirst;
            }
            v30 = (float *)((char *)&v15->point + (v25 & 0xFFFFFFFFFFFFFFF0ui64));
            v50 = v13;
            v51 = v13;
            if ( v13 )
            {
              v13->point.x_ = *v30;
              v13->point.y_ = v30[1];
              v13->direction.x_ = v30[2];
              v13->direction.y_ = v30[3];
            }
          }
          ++v13;
          linesa._Mylast = v13;
          goto LABEL_36;
        }
LABEL_37:
        v48 = *result;
        v7 = v64;
        v35 = *(float *)((char *)&v64->_Myfirst->direction.x_ + v10);
        LODWORD(optVelocity.x_) = *(_DWORD *)((char *)&v64->_Myfirst->direction.y_ + v10) ^ _xmm[0];
        optVelocity.y_ = v35;
        *result = *RVO::Vector2::operator*(&optVelocity, &v55, radius);
        v36 = 0i64;
        v37 = v13 - v15;
        if ( v37 )
        {
          v38 = (float *)&v15->direction;
          while ( 1 )
          {
            v39 = RVO::Vector2::operator-((RVO::Vector2 *)v38 - 1, &v57, result);
            if ( (float)((float)(v39->y_ * *v38) - (float)(v39->x_ * v38[1])) > 0.0 )
            {
              v47 = *result;
              if ( !RVO::linearProgram1(&linesa, v36, radius, &optVelocity, 1, result) )
                break;
            }
            ++v36;
            v38 += 4;
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
        v40 = (float *)((char *)&v64->_Myfirst->point + v66);
        v41 = RVO::Vector2::operator-((RVO::Vector2 *)((char *)&v64->_Myfirst->point + v66), &v59, result);
        v8 = (float)(v40[2] * v41->y_) - (float)(v41->x_ * v40[3]);
        if ( v15 )
        {
          operator delete[](v15);
          linesa._Myfirst = 0i64;
          linesa._Mylast = 0i64;
          linesa._Myend = 0i64;
        }
        v6 = v65;
      }
      v46 = ++v5;
      v10 += 16i64;
      v66 = v10;
      v9 = v7->_Myfirst;
    }
    while ( v5 < (_QWORD)((char *)v7->_Mylast - (char *)v7->_Myfirst) >> 4 );
  }
}

