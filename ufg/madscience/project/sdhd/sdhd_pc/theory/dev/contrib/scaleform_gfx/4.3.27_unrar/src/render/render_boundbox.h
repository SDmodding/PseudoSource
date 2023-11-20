// File Line: 84
// RVA: 0x881DF0
void __fastcall Scaleform::Render::ExpandBoundsToPath<Scaleform::Render::Matrix2x4<float>>(Scaleform::Render::ShapeDataInterface *shape, Scaleform::Render::Matrix2x4<float> *trans, Scaleform::Render::ShapePosInfo *pos, float *coord, Scaleform::Render::Rect<float> *bounds)
{
  float v5; // xmm2_4
  float v6; // xmm3_4
  Scaleform::Render::Rect<float> *v7; // rbx
  float *v8; // rdi
  Scaleform::Render::ShapePosInfo *v9; // rbp
  float *v10; // rsi
  Scaleform::Render::ShapeDataInterface *v11; // r14
  float v12; // xmm3_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm0_4
  Scaleform::RefCountImplCoreVtbl *v18; // rax
  float v19; // xmm11_4
  float v20; // xmm9_4
  int i; // eax
  float v22; // xmm2_4
  float v23; // xmm3_4
  float v24; // xmm3_4
  float v25; // xmm0_4
  float v26; // xmm1_4
  float v27; // xmm1_4
  float v28; // xmm1_4
  float v29; // xmm0_4
  float v30; // xmm2_4
  float v31; // xmm3_4
  float v32; // xmm2_4
  float v33; // xmm3_4
  float v34; // xmm3_4
  float v35; // xmm6_4
  float v36; // xmm4_4
  float v37; // xmm0_4
  float v38; // xmm5_4
  float v39; // xmm3_4
  float v40; // xmm0_4
  float v41; // xmm4_4
  float v42; // xmm0_4
  float v43; // xmm0_4
  float v44; // xmm0_4
  float v45; // xmm4_4
  float v46; // xmm3_4
  float v47; // xmm0_4
  float v48; // xmm5_4
  float v49; // xmm3_4
  float v50; // xmm0_4
  float v51; // xmm4_4
  float v52; // xmm0_4
  float v53; // xmm0_4
  float v54; // xmm0_4
  float v55; // xmm0_4
  float v56; // xmm2_4
  float v57; // xmm1_4
  float v58; // xmm3_4
  float v59; // xmm2_4
  float v60; // xmm0_4
  float v61; // xmm2_4
  float v62; // xmm3_4
  float v63; // xmm3_4
  float v64; // xmm2_4
  float v65; // xmm3_4
  float v66; // xmm7_4
  float v67; // xmm7_4
  float v68; // xmm10_4
  float v69; // xmm12_4
  float v70; // xmm0_4
  float v71; // xmm1_4
  float v72; // xmm6_4
  float v73; // xmm4_4
  float v74; // xmm7_4
  float v75; // xmm2_4
  float v76; // xmm0_4
  float v77; // xmm0_4
  float v78; // xmm0_4
  float v79; // xmm0_4
  float v80; // xmm1_4
  float v81; // xmm2_4
  float v82; // xmm7_4
  float v83; // xmm4_4
  float v84; // xmm5_4
  float v85; // xmm1_4
  float v86; // xmm0_4
  float v87; // xmm2_4
  float v88; // xmm0_4
  float v89; // xmm0_4
  float v90; // xmm0_4
  float v91; // xmm7_4
  float v92; // xmm10_4
  float v93; // xmm12_4
  float v94; // xmm1_4
  float v95; // xmm5_4
  float v96; // xmm4_4
  float v97; // xmm7_4
  float v98; // xmm0_4
  float v99; // xmm1_4
  float v100; // xmm0_4
  float v101; // xmm0_4
  float v102; // xmm0_4
  float v103; // xmm1_4
  float v104; // xmm2_4
  float v105; // xmm7_4
  float v106; // xmm4_4
  float v107; // xmm5_4
  float v108; // xmm1_4
  float v109; // xmm0_4
  float v110; // xmm2_4
  float v111; // xmm0_4
  float v112; // xmm0_4
  float v113; // xmm0_4
  float v114; // xmm0_4
  float v115; // xmm2_4
  float v116; // xmm1_4
  float v117; // xmm3_4
  float v118; // xmm2_4
  float v119; // xmm0_4
  float t2; // [rsp+F0h] [rbp+8h]

  v5 = *coord;
  v6 = coord[1];
  v7 = bounds;
  v8 = coord;
  v9 = pos;
  v10 = (float *)trans;
  v11 = shape;
  *coord = (float)((float)(*coord * trans->M[0][0]) + (float)(coord[1] * trans->M[0][1])) + trans->M[0][3];
  v12 = (float)((float)(v6 * trans->M[1][1]) + (float)(v5 * trans->M[1][0])) + trans->M[1][3];
  coord[1] = v12;
  v13 = *coord;
  v14 = v7->x1;
  if ( v7->x1 >= *coord )
    v14 = *coord;
  v7->x1 = v14;
  v15 = v7->y1;
  if ( v15 >= v12 )
    v15 = v12;
  v16 = v7->x2;
  v7->y1 = v15;
  if ( v13 >= v16 )
    v16 = v13;
  v17 = v7->y2;
  v7->x2 = v16;
  if ( v12 >= v17 )
    v17 = v12;
  v18 = shape->vfptr;
  v7->y2 = v17;
  v19 = *coord;
  v20 = coord[1];
  for ( i = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, Scaleform::Render::ShapePosInfo *, float *))v18[9].__vecDelDtor)(
              shape,
              pos,
              coord);
        i;
        i = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, Scaleform::Render::ShapePosInfo *, float *))v11->vfptr[9].__vecDelDtor)(
              v11,
              v9,
              v8) )
  {
    switch ( i )
    {
      case 1:
        v22 = *v8;
        v23 = v8[1];
        *v8 = (float)((float)(*v8 * *v10) + (float)(v8[1] * v10[1])) + v10[3];
        v24 = (float)((float)(v23 * v10[5]) + (float)(v22 * v10[4])) + v10[7];
        v8[1] = v24;
        v25 = *v8;
        v26 = v7->x1;
        if ( v7->x1 >= *v8 )
          v26 = *v8;
        v7->x1 = v26;
        v27 = v7->y1;
        if ( v27 >= v24 )
          v27 = v24;
        v7->y1 = v27;
        v28 = v7->x2;
        if ( v25 >= v28 )
          v28 = v25;
        v29 = v7->y2;
        v7->x2 = v28;
        if ( v24 >= v29 )
          v29 = v24;
        v7->y2 = v29;
        v19 = *v8;
        v20 = v8[1];
        break;
      case 2:
        v30 = *v8;
        v31 = v8[1];
        *v8 = (float)((float)(v8[1] * v10[1]) + (float)(*v8 * *v10)) + v10[3];
        v8[1] = (float)((float)(v31 * v10[5]) + (float)(v30 * v10[4])) + v10[7];
        v32 = v8[2];
        v33 = v8[3];
        v8[2] = (float)((float)(v8[3] * v10[1]) + (float)(v8[2] * *v10)) + v10[3];
        v34 = (float)((float)(v33 * v10[5]) + (float)(v32 * v10[4])) + v10[7];
        v8[3] = v34;
        v35 = *v8;
        v36 = v8[2];
        v37 = (float)((float)(*v8 * 2.0) - v19) - v36;
        if ( v37 != 0.0 )
        {
          v38 = (float)(v35 - v19) / v37;
          if ( v38 > 0.0 && v38 < 1.0 )
          {
            v39 = (float)((float)((float)((float)((float)(v34 - v8[1]) * v38) + v8[1])
                                - (float)((float)((float)(v8[1] - v20) * v38) + v20))
                        * v38)
                + (float)((float)((float)(v8[1] - v20) * v38) + v20);
            v40 = v7->x1;
            v41 = (float)((float)((float)((float)((float)(v36 - v35) * v38) + v35)
                                - (float)((float)((float)(v35 - v19) * v38) + v19))
                        * v38)
                + (float)((float)((float)(v35 - v19) * v38) + v19);
            if ( v7->x1 >= v41 )
              v40 = v41;
            v7->x1 = v40;
            v42 = v7->y1;
            if ( v42 >= v39 )
              v42 = v39;
            v7->y1 = v42;
            v43 = v7->x2;
            if ( v41 >= v43 )
              v43 = v41;
            v7->x2 = v43;
            v44 = v7->y2;
            if ( v39 >= v44 )
              v44 = v39;
            v7->y2 = v44;
          }
        }
        v45 = v8[1];
        v46 = v8[3];
        v47 = (float)((float)(v8[1] * 2.0) - v20) - v46;
        if ( v47 != 0.0 )
        {
          v48 = (float)(v45 - v20) / v47;
          if ( v48 > 0.0 && v48 < 1.0 )
          {
            v49 = (float)((float)((float)((float)((float)(v46 - v45) * v48) + v45)
                                - (float)((float)((float)(v45 - v20) * v48) + v20))
                        * v48)
                + (float)((float)((float)(v45 - v20) * v48) + v20);
            v50 = v7->x1;
            v51 = (float)((float)((float)((float)((float)(v8[2] - *v8) * v48) + *v8)
                                - (float)((float)((float)(*v8 - v19) * v48) + v19))
                        * v48)
                + (float)((float)((float)(*v8 - v19) * v48) + v19);
            if ( v7->x1 >= v51 )
              v50 = (float)((float)((float)((float)((float)(v8[2] - *v8) * v48) + *v8)
                                  - (float)((float)((float)(*v8 - v19) * v48) + v19))
                          * v48)
                  + (float)((float)((float)(*v8 - v19) * v48) + v19);
            v7->x1 = v50;
            v52 = v7->y1;
            if ( v52 >= v49 )
              v52 = v49;
            v7->y1 = v52;
            v53 = v7->x2;
            if ( v51 >= v53 )
              v53 = v51;
            v7->x2 = v53;
            v54 = v7->y2;
            if ( v49 >= v54 )
              v54 = v49;
            v7->y2 = v54;
          }
        }
        v55 = v8[2];
        v56 = v7->x1;
        v57 = v8[3];
        if ( v7->x1 >= v55 )
          v56 = v8[2];
        v58 = v7->y1;
        v7->x1 = v56;
        if ( v58 >= v57 )
          v58 = v57;
        v59 = v7->x2;
        v7->y1 = v58;
        if ( v55 >= v59 )
          v59 = v55;
        v60 = v7->y2;
        v7->x2 = v59;
        if ( v57 >= v60 )
          v60 = v57;
        v7->y2 = v60;
        v19 = v8[2];
        v20 = v8[3];
        break;
      case 3:
        v61 = *v8;
        v62 = v8[1];
        *v8 = (float)((float)(v62 * v10[1]) + (float)(*v8 * *v10)) + v10[3];
        v8[1] = (float)((float)(v62 * v10[5]) + (float)(v61 * v10[4])) + v10[7];
        v63 = v8[3];
        v64 = v8[2];
        v8[2] = (float)((float)(v8[3] * v10[1]) + (float)(v8[2] * *v10)) + v10[3];
        v65 = (float)((float)(v63 * v10[5]) + (float)(v64 * v10[4])) + v10[7];
        v8[3] = v65;
        v66 = v8[4];
        v8[3] = (float)((float)(v8[4] * v10[1]) + (float)(v65 * *v10)) + v10[3];
        v67 = (float)((float)(v66 * v10[5]) + (float)(v65 * v10[4])) + v10[7];
        v8[4] = v67;
        v68 = v8[2];
        v69 = *v8;
        Scaleform::Render::Math2D::CubicCurveExtremum(v19, *v8, v8[2], v67, (float *)&bounds, &t2);
        if ( *(float *)&bounds > 0.0 && *(float *)&bounds < 1.0 )
        {
          v70 = v8[1];
          v71 = (float)((float)(v8[3] - v70) * *(float *)&bounds) + v70;
          v72 = (float)((float)(v68 - v69) * *(float *)&bounds) + v69;
          v73 = (float)((float)(v72 - (float)((float)((float)(v69 - v19) * *(float *)&bounds) + v19)) * *(float *)&bounds)
              + (float)((float)((float)(v69 - v19) * *(float *)&bounds) + v19);
          v74 = (float)((float)((float)((float)((float)((float)((float)((float)(v67 - v68) * *(float *)&bounds) + v68)
                                                      - v72)
                                              * *(float *)&bounds)
                                      + v72)
                              - v73)
                      * *(float *)&bounds)
              + v73;
          v75 = (float)((float)((float)((float)((float)((float)((float)((float)(v8[5] - v8[3]) * *(float *)&bounds)
                                                              + v8[3])
                                                      - v71)
                                              * *(float *)&bounds)
                                      + v71)
                              - (float)((float)((float)(v71
                                                      - (float)((float)((float)(v70 - v20) * *(float *)&bounds) + v20))
                                              * *(float *)&bounds)
                                      + (float)((float)((float)(v70 - v20) * *(float *)&bounds) + v20)))
                      * *(float *)&bounds)
              + (float)((float)((float)(v71 - (float)((float)((float)(v70 - v20) * *(float *)&bounds) + v20))
                              * *(float *)&bounds)
                      + (float)((float)((float)(v70 - v20) * *(float *)&bounds) + v20));
          v76 = v7->x1;
          if ( v7->x1 >= v74 )
            v76 = v74;
          v7->x1 = v76;
          v77 = v7->y1;
          if ( v77 >= v75 )
            v77 = v75;
          v7->y1 = v77;
          v78 = v7->x2;
          if ( v74 >= v78 )
            v78 = v74;
          v7->x2 = v78;
          v79 = v7->y2;
          if ( v75 >= v79 )
            v79 = v75;
          v7->y2 = v79;
        }
        if ( t2 > 0.0 && t2 < 1.0 )
        {
          v80 = v8[1];
          v81 = (float)((float)(v8[3] - v80) * t2) + v80;
          v82 = (float)((float)(v8[2] - *v8) * t2) + *v8;
          v83 = (float)((float)(v80 - v20) * t2) + v20;
          v84 = (float)((float)(v82 - (float)((float)((float)(*v8 - v19) * t2) + v19)) * t2)
              + (float)((float)((float)(*v8 - v19) * t2) + v19);
          v85 = (float)((float)((float)((float)((float)((float)((float)((float)(v8[5] - v8[3]) * t2) + v8[3]) - v81) * t2)
                                      + v81)
                              - (float)((float)((float)(v81 - v83) * t2) + v83))
                      * t2)
              + (float)((float)((float)(v81 - v83) * t2) + v83);
          v86 = v7->x1;
          v87 = (float)((float)((float)((float)((float)((float)((float)((float)(v8[4] - v8[2]) * t2) + v8[2]) - v82) * t2)
                                      + v82)
                              - v84)
                      * t2)
              + v84;
          if ( v7->x1 >= v87 )
            v86 = (float)((float)((float)((float)((float)((float)((float)((float)(v8[4] - v8[2]) * t2) + v8[2]) - v82)
                                                * t2)
                                        + v82)
                                - v84)
                        * t2)
                + v84;
          v7->x1 = v86;
          v88 = v7->y1;
          if ( v88 >= v85 )
            v88 = v85;
          v7->y1 = v88;
          v89 = v7->x2;
          if ( v87 >= v89 )
            v89 = v87;
          v7->x2 = v89;
          v90 = v7->y2;
          if ( v85 >= v90 )
            v90 = v85;
          v7->y2 = v90;
        }
        v91 = v8[5];
        v92 = v8[3];
        v93 = v8[1];
        Scaleform::Render::Math2D::CubicCurveExtremum(v20, v8[1], v8[3], v8[5], (float *)&bounds, &t2);
        if ( *(float *)&bounds > 0.0 && *(float *)&bounds < 1.0 )
        {
          v94 = (float)((float)(v92 - v93) * *(float *)&bounds) + v93;
          v95 = (float)((float)(v8[2] - *v8) * *(float *)&bounds) + *v8;
          v96 = (float)((float)(v95 - (float)((float)((float)(*v8 - v19) * *(float *)&bounds) + v19)) * *(float *)&bounds)
              + (float)((float)((float)(*v8 - v19) * *(float *)&bounds) + v19);
          v97 = (float)((float)((float)((float)((float)((float)((float)((float)(v91 - v92) * *(float *)&bounds) + v92)
                                                      - v94)
                                              * *(float *)&bounds)
                                      + v94)
                              - (float)((float)((float)(v94
                                                      - (float)((float)((float)(v93 - v20) * *(float *)&bounds) + v20))
                                              * *(float *)&bounds)
                                      + (float)((float)((float)(v93 - v20) * *(float *)&bounds) + v20)))
                      * *(float *)&bounds)
              + (float)((float)((float)(v94 - (float)((float)((float)(v93 - v20) * *(float *)&bounds) + v20))
                              * *(float *)&bounds)
                      + (float)((float)((float)(v93 - v20) * *(float *)&bounds) + v20));
          v98 = v7->x1;
          v99 = (float)((float)((float)((float)((float)((float)((float)((float)(v8[4] - v8[2]) * *(float *)&bounds)
                                                              + v8[2])
                                                      - v95)
                                              * *(float *)&bounds)
                                      + v95)
                              - v96)
                      * *(float *)&bounds)
              + v96;
          if ( v7->x1 >= v99 )
            v98 = (float)((float)((float)((float)((float)((float)((float)((float)(v8[4] - v8[2]) * *(float *)&bounds)
                                                                + v8[2])
                                                        - v95)
                                                * *(float *)&bounds)
                                        + v95)
                                - v96)
                        * *(float *)&bounds)
                + v96;
          v7->x1 = v98;
          v100 = v7->y1;
          if ( v100 >= v97 )
            v100 = v97;
          v7->y1 = v100;
          v101 = v7->x2;
          if ( v99 >= v101 )
            v101 = v99;
          v7->x2 = v101;
          v102 = v7->y2;
          if ( v97 >= v102 )
            v102 = v97;
          v7->y2 = v102;
        }
        if ( t2 > 0.0 && t2 < 1.0 )
        {
          v103 = v8[1];
          v104 = (float)((float)(v8[3] - v103) * t2) + v103;
          v105 = (float)((float)(v8[2] - *v8) * t2) + *v8;
          v106 = (float)((float)(v103 - v20) * t2) + v20;
          v107 = (float)((float)(v105 - (float)((float)((float)(*v8 - v19) * t2) + v19)) * t2)
               + (float)((float)((float)(*v8 - v19) * t2) + v19);
          v108 = (float)((float)((float)((float)((float)((float)((float)((float)(v8[5] - v8[3]) * t2) + v8[3]) - v104)
                                               * t2)
                                       + v104)
                               - (float)((float)((float)(v104 - v106) * t2) + v106))
                       * t2)
               + (float)((float)((float)(v104 - v106) * t2) + v106);
          v109 = v7->x1;
          v110 = (float)((float)((float)((float)((float)((float)((float)((float)(v8[4] - v8[2]) * t2) + v8[2]) - v105)
                                               * t2)
                                       + v105)
                               - v107)
                       * t2)
               + v107;
          if ( v7->x1 >= v110 )
            v109 = (float)((float)((float)((float)((float)((float)((float)((float)(v8[4] - v8[2]) * t2) + v8[2]) - v105)
                                                 * t2)
                                         + v105)
                                 - v107)
                         * t2)
                 + v107;
          v7->x1 = v109;
          v111 = v7->y1;
          if ( v111 >= v108 )
            v111 = v108;
          v7->y1 = v111;
          v112 = v7->x2;
          if ( v110 >= v112 )
            v112 = v110;
          v7->x2 = v112;
          v113 = v7->y2;
          if ( v108 >= v113 )
            v113 = v108;
          v7->y2 = v113;
        }
        v114 = v8[4];
        v115 = v7->x1;
        v116 = v8[5];
        if ( v7->x1 >= v114 )
          v115 = v8[4];
        v117 = v7->y1;
        v7->x1 = v115;
        if ( v117 >= v116 )
          v117 = v116;
        v118 = v7->x2;
        v7->y1 = v117;
        if ( v114 >= v118 )
          v118 = v114;
        v119 = v7->y2;
        v7->x2 = v118;
        if ( v116 >= v119 )
          v119 = v116;
        v7->y2 = v119;
        v19 = v8[4];
        v20 = v8[5];
        break;
    }
  }
}

// File Line: 195
// RVA: 0x881CE0
void __fastcall Scaleform::Render::ExpandBoundsToFill<Scaleform::Render::Matrix2x4<float>>(Scaleform::Render::ShapeDataInterface *shape, Scaleform::Render::Matrix2x4<float> *trans, Scaleform::Render::Rect<float> *bounds, Scaleform::Render::BoundEdges edgesToCheck)
{
  Scaleform::Render::BoundEdges v4; // edi
  Scaleform::Render::Rect<float> *v5; // rsi
  Scaleform::Render::Matrix2x4<float> *v6; // r14
  Scaleform::Render::ShapeDataInterface *v7; // rbx
  Scaleform::RefCountImplCoreVtbl *v8; // rax
  bool v9; // zf
  int v10; // [rsp+30h] [rbp-19h]
  int v11; // [rsp+34h] [rbp-15h]
  float coord; // [rsp+40h] [rbp-9h]
  Scaleform::Render::ShapePosInfo pos; // [rsp+58h] [rbp+Fh]

  v4 = edgesToCheck;
  v5 = bounds;
  v6 = trans;
  v7 = shape;
  pos.Pos = ((__int64 (*)(void))shape->vfptr[6].__vecDelDtor)();
  LODWORD(pos.Sfactor) = (_DWORD)FLOAT_1_0;
  v8 = v7->vfptr;
  *(_QWORD *)&pos.StartX = 0i64;
  *(_QWORD *)&pos.LastX = 0i64;
  *(_QWORD *)&pos.FillBase = 0i64;
  *(_QWORD *)&pos.NumFillBits = 0i64;
  *(_QWORD *)&pos.Fill0 = 0i64;
  pos.Stroke = 0;
  pos.Initialized = 0;
  if ( ((unsigned int (__fastcall *)(Scaleform::Render::ShapeDataInterface *, Scaleform::Render::ShapePosInfo *, float *, int *))v8[8].__vecDelDtor)(
         v7,
         &pos,
         &coord,
         &v10) )
  {
    do
    {
      if ( v4 )
      {
        if ( v4 != 1 )
        {
          if ( v4 == 2 )
            goto LABEL_11;
          goto LABEL_5;
        }
        v9 = v10 == v11;
      }
      else
      {
        v9 = (v10 == 0) == (v11 == 0);
      }
      if ( !v9 )
      {
LABEL_11:
        Scaleform::Render::ExpandBoundsToPath<Scaleform::Render::Matrix2x4<float>>(v7, v6, &pos, &coord, v5);
        continue;
      }
LABEL_5:
      v7->vfptr[10].__vecDelDtor((Scaleform::RefCountImplCore *)&v7->vfptr, (unsigned int)&pos);
    }
    while ( ((unsigned int (__fastcall *)(Scaleform::Render::ShapeDataInterface *, Scaleform::Render::ShapePosInfo *, float *, int *))v7->vfptr[8].__vecDelDtor)(
              v7,
              &pos,
              &coord,
              &v10) );
  }
}

// File Line: 242
// RVA: 0x92A110
Scaleform::Render::Rect<float> *__fastcall Scaleform::Render::ComputeBoundsRoundStroke<Scaleform::Render::Matrix2x4<float>>(Scaleform::Render::Rect<float> *result, Scaleform::Render::ShapeDataInterface *shape, Scaleform::Render::Matrix2x4<float> *trans, Scaleform::Render::ShapePosInfo *pos, float *coord, unsigned int *styles)
{
  Scaleform::Render::ShapePosInfo *v6; // rbp
  Scaleform::Render::Matrix2x4<float> *v7; // rbx
  Scaleform::Render::ShapeDataInterface *v8; // rsi
  Scaleform::Render::Rect<float> *bounds; // rdi
  float v10; // xmm0_4
  int v11; // eax
  __m128 v12; // xmm1
  __m128 v13; // xmm1
  __m128 v14; // xmm2
  float v15; // xmm6_4
  float v16; // xmm3_4
  float v17; // xmm1_4
  float v18; // xmm0_4
  float v19; // xmm6_4
  void (__fastcall ***v20)(_QWORD, signed __int64); // rcx
  void (__fastcall ***v21)(_QWORD, signed __int64); // rcx
  float v23; // [rsp+38h] [rbp-40h]
  int v24; // [rsp+40h] [rbp-38h]
  __int64 v25; // [rsp+50h] [rbp-28h]
  __int64 v26; // [rsp+58h] [rbp-20h]

  v6 = pos;
  v7 = trans;
  v8 = shape;
  bounds = result;
  result->x1 = 1.0e30;
  result->y1 = 1.0e30;
  result->x2 = -1.0e30;
  result->y2 = -1.0e30;
  v25 = 0i64;
  v26 = 0i64;
  ((void (__fastcall *)(Scaleform::Render::ShapeDataInterface *, _QWORD, float *))shape->vfptr[5].__vecDelDtor)(
    shape,
    styles[2],
    &v23);
  v10 = *(float *)&FLOAT_1_0;
  v11 = v24 & 6;
  if ( v24 & 6 )
  {
    if ( v11 == 2 )
    {
      v13 = (__m128)LODWORD(v7->M[0][0]);
      v13.m128_f32[0] = (float)(v13.m128_f32[0] * v13.m128_f32[0]) + (float)(v7->M[1][0] * v7->M[1][0]);
      LODWORD(v10) = (unsigned __int128)_mm_sqrt_ps(v13);
    }
    else if ( v11 == 4 )
    {
      v12 = (__m128)LODWORD(v7->M[0][1]);
      v12.m128_f32[0] = (float)(v12.m128_f32[0] * v12.m128_f32[0]) + (float)(v7->M[1][1] * v7->M[1][1]);
      LODWORD(v10) = (unsigned __int128)_mm_sqrt_ps(v12);
    }
  }
  else
  {
    v14 = (__m128)LODWORD(v7->M[0][1]);
    v14.m128_f32[0] = (float)((float)((float)(v14.m128_f32[0] + v7->M[0][0]) * 0.70710677)
                            * (float)((float)(v14.m128_f32[0] + v7->M[0][0]) * 0.70710677))
                    + (float)((float)((float)(v7->M[1][1] + v7->M[1][0]) * 0.70710677)
                            * (float)((float)(v7->M[1][1] + v7->M[1][0]) * 0.70710677));
    LODWORD(v10) = (unsigned __int128)_mm_sqrt_ps(v14);
  }
  v15 = v23 * v10;
  Scaleform::Render::ExpandBoundsToPath<Scaleform::Render::Matrix2x4<float>>(v8, v7, v6, coord, bounds);
  v16 = bounds->x2;
  if ( v16 >= bounds->x1 )
  {
    v17 = bounds->y2;
    v18 = bounds->y1;
    if ( v17 >= v18 )
    {
      v19 = v15 * 0.5;
      bounds->x1 = bounds->x1 - v19;
      bounds->y1 = v18 - v19;
      bounds->x2 = v16 + v19;
      bounds->y2 = v17 + v19;
    }
  }
  v20 = (void (__fastcall ***)(_QWORD, signed __int64))v26;
  if ( v26 && !_InterlockedDecrement((volatile signed __int32 *)(v26 + 8)) && v20 )
    (**v20)(v20, 1i64);
  v21 = (void (__fastcall ***)(_QWORD, signed __int64))v25;
  if ( v25 && !_InterlockedDecrement((volatile signed __int32 *)(v25 + 8)) && v21 )
    (**v21)(v21, 1i64);
  return bounds;
}

// File Line: 277
// RVA: 0x92BCD0
void __fastcall Scaleform::Render::ExpandBoundsToStrokesSimplified<Scaleform::Render::Matrix2x4<float>>(Scaleform::Render::ShapeDataInterface *shape, Scaleform::Render::Matrix2x4<float> *trans, Scaleform::Render::Rect<float> *bounds)
{
  Scaleform::Render::Rect<float> *v3; // rbx
  Scaleform::Render::Matrix2x4<float> *v4; // rsi
  Scaleform::Render::ShapeDataInterface *v5; // rdi
  unsigned int v6; // eax
  float v7; // xmm6_4
  float v8; // xmm0_4
  float v9; // xmm5_4
  float v10; // xmm2_4
  float v11; // xmm1_4
  float v12; // xmm3_4
  float v13; // xmm4_4
  float v14; // xmm0_4
  unsigned int styles; // [rsp+30h] [rbp-29h]
  int v16; // [rsp+38h] [rbp-21h]
  Scaleform::Render::Rect<float> result; // [rsp+40h] [rbp-19h]
  float coord; // [rsp+50h] [rbp-9h]
  Scaleform::Render::ShapePosInfo pos; // [rsp+68h] [rbp+Fh]

  v3 = bounds;
  v4 = trans;
  v5 = shape;
  v6 = ((__int64 (*)(void))shape->vfptr[6].__vecDelDtor)();
  LODWORD(pos.Sfactor) = (_DWORD)FLOAT_1_0;
  pos.Pos = v6;
  *(_QWORD *)&pos.StartX = 0i64;
  *(_QWORD *)&pos.LastX = 0i64;
  *(_QWORD *)&pos.FillBase = 0i64;
  *(_QWORD *)&pos.NumFillBits = 0i64;
  *(_QWORD *)&pos.Fill0 = 0i64;
  pos.Stroke = 0;
  pos.Initialized = 0;
  while ( ((unsigned int (__fastcall *)(Scaleform::Render::ShapeDataInterface *, Scaleform::Render::ShapePosInfo *, float *, unsigned int *))v5->vfptr[8].__vecDelDtor)(
            v5,
            &pos,
            &coord,
            &styles) )
  {
    if ( v16 )
    {
      Scaleform::Render::ComputeBoundsRoundStroke<Scaleform::Render::Matrix2x4<float>>(
        &result,
        v5,
        v4,
        &pos,
        &coord,
        &styles);
      v7 = result.x2;
      v8 = result.x1;
      if ( result.x2 >= result.x1 )
      {
        v9 = result.y2;
        v10 = result.y1;
        if ( result.y2 >= result.y1 )
        {
          v11 = v3->x1;
          if ( v3->x1 >= result.x1 )
            v11 = result.x1;
          v12 = v3->y1;
          v3->x1 = v11;
          if ( v12 >= v10 )
            v12 = v10;
          v13 = v3->x2;
          v3->y1 = v12;
          if ( v8 >= v13 )
            v13 = v8;
          v14 = v3->y2;
          v3->x2 = v13;
          if ( v10 >= v14 )
            v14 = v10;
          v3->y2 = v14;
          if ( v11 >= v7 )
            v11 = v7;
          v3->x1 = v11;
          if ( v12 >= v9 )
            v12 = v9;
          v3->y1 = v12;
          if ( v7 >= v13 )
            v13 = v7;
          v3->x2 = v13;
          if ( v9 >= v14 )
            v14 = v9;
          v3->y2 = v14;
        }
      }
    }
    else
    {
      v5->vfptr[10].__vecDelDtor((Scaleform::RefCountImplCore *)&v5->vfptr, (unsigned int)&pos);
    }
  }
}

// File Line: 310
// RVA: 0x92A090
Scaleform::Render::Rect<float> *__fastcall Scaleform::Render::ComputeBoundsFillAndStrokesSimplified<Scaleform::Render::Matrix2x4<float>>(Scaleform::Render::Rect<float> *result, Scaleform::Render::ShapeDataInterface *shape, Scaleform::Render::Matrix2x4<float> *trans, Scaleform::Render::BoundEdges edgesToCheck)
{
  Scaleform::Render::Matrix2x4<float> *v4; // rsi
  Scaleform::Render::ShapeDataInterface *v5; // rdi
  Scaleform::Render::Rect<float> *v6; // rbx

  v4 = trans;
  v5 = shape;
  v6 = result;
  result->x1 = 1.0e30;
  result->y1 = 1.0e30;
  result->x2 = -1.0e30;
  result->y2 = -1.0e30;
  Scaleform::Render::ExpandBoundsToFill<Scaleform::Render::Matrix2x4<float>>(shape, trans, result, edgesToCheck);
  if ( ((unsigned int (__fastcall *)(Scaleform::Render::ShapeDataInterface *))v5->vfptr[3].__vecDelDtor)(v5) )
  {
    ((void (__fastcall *)(Scaleform::Render::ShapeDataInterface *))v5->vfptr[7].__vecDelDtor)(v5);
    Scaleform::Render::ExpandBoundsToStrokesSimplified<Scaleform::Render::Matrix2x4<float>>(v5, v4, v6);
  }
  return v6;
}

// File Line: 335
// RVA: 0x92A2D0
Scaleform::Render::Rect<float> *__fastcall Scaleform::Render::ComputeBoundsRoundStrokeSorter<Scaleform::Render::Matrix2x4<float>>(Scaleform::Render::Rect<float> *result, Scaleform::Render::ShapeDataInterface *shape, Scaleform::Render::ShapePosInfo *pos, unsigned int strokeStyleIdx, Scaleform::Render::Matrix2x4<float> *trans, float scaledWidth, Scaleform::Render::StrokeGenerator *gen)
{
  unsigned int v7; // eax
  Scaleform::Render::Matrix2x4<float> *v8; // r9
  Scaleform::Render::Rect<float> *v9; // rbx
  Scaleform::Render::StrokeGenerator *v10; // rsi
  unsigned int v11; // eax
  __int64 v12; // rdx
  float v13; // xmm10_4
  float v14; // xmm11_4
  float v15; // xmm8_4
  unsigned __int64 v16; // rcx
  __int64 v17; // r15
  float v18; // xmm7_4
  unsigned int v19; // edi
  Scaleform::Render::StrokeSorter::VertexType **v20; // r13
  Scaleform::Render::StrokeSorter::PathType *v21; // r12
  int v22; // ecx
  unsigned int v23; // eax
  signed __int64 v24; // rsi
  unsigned __int8 v25; // al
  int v26; // ecx
  unsigned int v27; // eax
  float v28; // xmm9_4
  float *v29; // rdx
  float v30; // xmm6_4
  float v31; // xmm0_4
  float v32; // xmm4_4
  float v33; // xmm0_4
  float v34; // xmm3_4
  float v35; // xmm0_4
  float v36; // xmm1_4
  float v37; // xmm0_4
  float v38; // xmm0_4
  float v39; // xmm0_4
  float v40; // xmm3_4
  float v41; // xmm5_4
  float v42; // xmm0_4
  float v43; // xmm4_4
  float v44; // xmm2_4
  float v45; // xmm0_4
  float v46; // xmm3_4
  float v47; // xmm0_4
  float v48; // xmm0_4
  float v49; // xmm0_4
  float v50; // xmm0_4
  float v51; // xmm1_4
  float v52; // xmm0_4
  float v53; // xmm0_4
  int v54; // ecx
  unsigned int v55; // eax
  unsigned int v56; // edi
  unsigned __int64 v57; // rax
  int v58; // ecx
  float *v59; // rbp
  unsigned int v60; // eax
  float v61; // xmm13_4
  float v62; // xmm14_4
  float *v63; // r14
  float v64; // xmm10_4
  float v65; // xmm9_4
  float v66; // xmm0_4
  float v67; // xmm6_4
  float v68; // xmm1_4
  float v69; // xmm4_4
  float v70; // xmm0_4
  float v71; // xmm2_4
  float v72; // xmm0_4
  float v73; // xmm1_4
  float v74; // xmm0_4
  float v75; // xmm0_4
  float v76; // xmm0_4
  float v77; // xmm9_4
  float v78; // xmm0_4
  float v79; // xmm6_4
  float v80; // xmm1_4
  float v81; // xmm4_4
  float v82; // xmm0_4
  float v83; // xmm2_4
  float v84; // xmm0_4
  float v85; // xmm1_4
  float v86; // xmm0_4
  float v87; // xmm0_4
  float v88; // xmm0_4
  float v89; // xmm6_4
  float v90; // xmm11_4
  float v91; // xmm12_4
  float v92; // xmm9_4
  float v93; // xmm0_4
  float v94; // xmm4_4
  float v95; // xmm3_4
  float v96; // xmm0_4
  float v97; // xmm5_4
  float v98; // xmm0_4
  float v99; // xmm1_4
  float v100; // xmm0_4
  float v101; // xmm0_4
  float v102; // xmm0_4
  float v103; // xmm9_4
  float v104; // xmm4_4
  float v105; // xmm3_4
  float v106; // xmm0_4
  float v107; // xmm5_4
  float v108; // xmm0_4
  float v109; // xmm1_4
  float v110; // xmm0_4
  float v111; // xmm0_4
  float v112; // xmm0_4
  float v113; // xmm0_4
  float v114; // xmm1_4
  float v115; // xmm0_4
  float v116; // xmm0_4
  float v117; // xmm1_4
  float v118; // xmm0_4
  float v119; // xmm2_4
  Scaleform::Render::Rect<float> *v120; // rax
  float v121; // xmm4_4
  float v122; // xmm3_4
  float v123; // xmm3_4
  float v124; // xmm2_4
  float v125; // xmm4_4
  float t2; // [rsp+30h] [rbp-E8h]
  unsigned int v127; // [rsp+34h] [rbp-E4h]
  unsigned int v128; // [rsp+38h] [rbp-E0h]
  Scaleform::Render::StrokeSorter::PathType **v129; // [rsp+40h] [rbp-D8h]
  float t1; // [rsp+120h] [rbp+8h]

  v7 = strokeStyleIdx;
  v8 = trans;
  v9 = result;
  result->x1 = 1.0e30;
  result->y1 = 1.0e30;
  result->x2 = -1.0e30;
  result->y2 = -1.0e30;
  v10 = gen;
  Scaleform::Render::AddStrokeToSorter<Scaleform::Render::Matrix2x4<float>>(shape, pos, v7, v8);
  v11 = 0;
  v127 = 0;
  if ( !LODWORD(v10->mStrokeSorter.OutPaths.Size) )
    goto LABEL_114;
  v12 = (__int64)v10->mStrokeSorter.OutPaths.Pages;
  v129 = v10->mStrokeSorter.OutPaths.Pages;
  v13 = FLOAT_2_0;
  v14 = *(float *)&FLOAT_1_0;
  do
  {
    v15 = 0.0;
    v16 = (unsigned __int64)v11 >> 4;
    v17 = v11 & 0xF;
    v18 = 0.0;
    v19 = 0;
    v128 = *(_DWORD *)(*(_QWORD *)(v12 + 8 * v16) + 8 * v17 + 4) & 0xFFFFFFF;
    if ( !v128 )
      goto LABEL_113;
    v20 = v10->mStrokeSorter.OutVertices.Pages;
    v21 = v10->mStrokeSorter.OutPaths.Pages[v16];
    do
    {
      v22 = v19;
      v23 = v21[v17].numVer & 0xFFFFFFF;
      if ( v19 >= v23 )
        v22 = v19 - v23;
      ++v19;
      v24 = (signed __int64)&v20[(unsigned __int64)(v22 + v21[v17].start) >> 4][((_BYTE)v22 + LOBYTE(v21[v17].start)) & 0xF];
      v25 = *(_BYTE *)(v24 + 12);
      if ( v25 < 2u )
      {
        v15 = *(float *)v24;
        v116 = v9->x1;
        v18 = *(float *)(v24 + 4);
        if ( v9->x1 >= *(float *)v24 )
          v116 = *(float *)v24;
        v117 = v9->y1;
        v9->x1 = v116;
        if ( v117 >= v18 )
          v117 = v18;
        v118 = v9->x2;
        v9->y1 = v117;
        if ( v15 >= v118 )
          v118 = v15;
        v9->x2 = v118;
        v53 = v9->y2;
        if ( v18 >= v53 )
          v53 = v18;
      }
      else if ( v25 == 2 )
      {
        v26 = v19;
        v27 = v21[v17].numVer & 0xFFFFFFF;
        if ( v19 >= v27 )
          v26 = v19 - v27;
        v28 = *(float *)v24;
        ++v19;
        v29 = &v20[(unsigned __int64)(v21[v17].start + v26) >> 4][(LOBYTE(v21[v17].start) + (_BYTE)v26) & 0xF].x;
        v30 = *v29;
        v31 = (float)((float)(*(float *)v24 * v13) - v15) - *v29;
        if ( v31 != 0.0 )
        {
          v32 = (float)(v28 - v15) / v31;
          if ( v32 > 0.0 && v32 < v14 )
          {
            v33 = (float)((float)(*(float *)(v24 + 4) - v18) * v32) + v18;
            v34 = (float)((float)((float)((float)((float)(v29[1] - *(float *)(v24 + 4)) * v32) + *(float *)(v24 + 4))
                                - v33)
                        * v32)
                + v33;
            v35 = v9->x1;
            v36 = (float)((float)((float)((float)((float)(v30 - v28) * v32) + v28)
                                - (float)((float)((float)(v28 - v15) * v32) + v15))
                        * v32)
                + (float)((float)((float)(v28 - v15) * v32) + v15);
            if ( v9->x1 >= v36 )
              v35 = (float)((float)((float)((float)((float)(v30 - v28) * v32) + v28)
                                  - (float)((float)((float)(v28 - v15) * v32) + v15))
                          * v32)
                  + (float)((float)((float)(v28 - v15) * v32) + v15);
            v9->x1 = v35;
            v37 = v9->y1;
            if ( v37 >= v34 )
              v37 = v34;
            v9->y1 = v37;
            v38 = v9->x2;
            if ( v36 >= v38 )
              v38 = (float)((float)((float)((float)((float)(v30 - v28) * v32) + v28)
                                  - (float)((float)((float)(v28 - v15) * v32) + v15))
                          * v32)
                  + (float)((float)((float)(v28 - v15) * v32) + v15);
            v9->x2 = v38;
            v39 = v9->y2;
            if ( v34 >= v39 )
              v39 = v34;
            v9->y2 = v39;
          }
        }
        v40 = *(float *)(v24 + 4);
        v41 = v29[1];
        v42 = (float)((float)(*(float *)(v24 + 4) * v13) - v18) - v41;
        if ( v42 != 0.0 )
        {
          v43 = (float)(v40 - v18) / v42;
          if ( v43 > 0.0 && v43 < v14 )
          {
            v44 = (float)((float)((float)((float)((float)(v41 - v40) * v43) + v40)
                                - (float)((float)((float)(v40 - v18) * v43) + v18))
                        * v43)
                + (float)((float)((float)(v40 - v18) * v43) + v18);
            v45 = v9->x1;
            v46 = (float)((float)((float)((float)((float)(v30 - v28) * v43) + v28)
                                - (float)((float)((float)(v28 - v15) * v43) + v15))
                        * v43)
                + (float)((float)((float)(v28 - v15) * v43) + v15);
            if ( v9->x1 >= v46 )
              v45 = (float)((float)((float)((float)((float)(v30 - v28) * v43) + v28)
                                  - (float)((float)((float)(v28 - v15) * v43) + v15))
                          * v43)
                  + (float)((float)((float)(v28 - v15) * v43) + v15);
            v9->x1 = v45;
            v47 = v9->y1;
            if ( v47 >= v44 )
              v47 = v44;
            v9->y1 = v47;
            v48 = v9->x2;
            if ( v46 >= v48 )
              v48 = (float)((float)((float)((float)((float)(v30 - v28) * v43) + v28)
                                  - (float)((float)((float)(v28 - v15) * v43) + v15))
                          * v43)
                  + (float)((float)((float)(v28 - v15) * v43) + v15);
            v9->x2 = v48;
            v49 = v9->y2;
            if ( v44 >= v49 )
              v49 = v44;
            v9->y2 = v49;
          }
        }
        v50 = v9->x1;
        if ( v9->x1 >= v30 )
          v50 = v30;
        v51 = v9->y1;
        v9->x1 = v50;
        if ( v51 >= v41 )
          v51 = v41;
        v52 = v9->x2;
        v9->y1 = v51;
        if ( v30 >= v52 )
          v52 = v30;
        v9->x2 = v52;
        v53 = v9->y2;
        if ( v41 >= v53 )
          v53 = v41;
        v15 = v30;
        v18 = v41;
      }
      else
      {
        if ( v25 != 3 )
          continue;
        v54 = v19;
        v55 = v21[v17].numVer & 0xFFFFFFF;
        if ( v19 >= v55 )
          v54 = v19 - v55;
        v56 = v19 + 1;
        v57 = v54 + v21[v17].start;
        v58 = v56;
        v59 = &v20[v57 >> 4][v57 & 0xF].x;
        v60 = v21[v17].numVer & 0xFFFFFFF;
        if ( v56 >= v60 )
          v58 = v56 - v60;
        v61 = *v59;
        v62 = *(float *)v24;
        v19 = v56 + 1;
        v63 = &v20[(unsigned __int64)(v21[v17].start + v58) >> 4][(LOBYTE(v21[v17].start) + (_BYTE)v58) & 0xF].x;
        v64 = *v63;
        Scaleform::Render::Math2D::CubicCurveExtremum(v15, *(float *)v24, *v59, *v63, &t1, &t2);
        v65 = t1;
        if ( t1 > 0.0 && t1 < v14 )
        {
          v66 = *(float *)(v24 + 4);
          v67 = (float)((float)(v61 - v62) * t1) + v62;
          v68 = (float)((float)(v59[1] - v66) * t1) + v66;
          v69 = (float)((float)(v67 - (float)((float)((float)(v62 - v15) * t1) + v15)) * t1)
              + (float)((float)((float)(v62 - v15) * t1) + v15);
          v70 = (float)((float)(v68 - (float)((float)((float)(v66 - v18) * t1) + v18)) * t1)
              + (float)((float)((float)(v66 - v18) * t1) + v18);
          v71 = (float)((float)((float)((float)((float)((float)((float)((float)(v63[1] - v59[1]) * t1) + v59[1]) - v68)
                                              * t1)
                                      + v68)
                              - v70)
                      * t1)
              + v70;
          v72 = v9->x1;
          v73 = (float)((float)((float)((float)((float)((float)((float)((float)(v64 - v61) * t1) + v61) - v67) * t1)
                                      + v67)
                              - v69)
                      * t1)
              + v69;
          if ( v9->x1 >= v73 )
            v72 = (float)((float)((float)((float)((float)((float)((float)((float)(v64 - v61) * t1) + v61) - v67) * t1)
                                        + v67)
                                - v69)
                        * t1)
                + v69;
          v9->x1 = v72;
          v74 = v9->y1;
          if ( v74 >= v71 )
            v74 = v71;
          v9->y1 = v74;
          v75 = v9->x2;
          if ( v73 >= v75 )
            v75 = (float)((float)((float)((float)((float)((float)((float)((float)(v64 - v61) * v65) + v61) - v67) * v65)
                                        + v67)
                                - v69)
                        * v65)
                + v69;
          v9->x2 = v75;
          v76 = v9->y2;
          if ( v71 >= v76 )
            v76 = v71;
          v9->y2 = v76;
        }
        v77 = t2;
        if ( t2 > 0.0 && t2 < v14 )
        {
          v78 = *(float *)(v24 + 4);
          v79 = (float)((float)(v61 - v62) * t2) + v62;
          v80 = (float)((float)(v59[1] - v78) * t2) + v78;
          v81 = (float)((float)(v79 - (float)((float)((float)(v62 - v15) * t2) + v15)) * t2)
              + (float)((float)((float)(v62 - v15) * t2) + v15);
          v82 = (float)((float)(v80 - (float)((float)((float)(v78 - v18) * t2) + v18)) * t2)
              + (float)((float)((float)(v78 - v18) * t2) + v18);
          v83 = (float)((float)((float)((float)((float)((float)((float)((float)(v63[1] - v59[1]) * t2) + v59[1]) - v80)
                                              * t2)
                                      + v80)
                              - v82)
                      * t2)
              + v82;
          v84 = v9->x1;
          v85 = (float)((float)((float)((float)((float)((float)((float)((float)(v64 - v61) * t2) + v61) - v79) * t2)
                                      + v79)
                              - v81)
                      * t2)
              + v81;
          if ( v9->x1 >= v85 )
            v84 = (float)((float)((float)((float)((float)((float)((float)((float)(v64 - v61) * t2) + v61) - v79) * t2)
                                        + v79)
                                - v81)
                        * t2)
                + v81;
          v9->x1 = v84;
          v86 = v9->y1;
          if ( v86 >= v83 )
            v86 = v83;
          v9->y1 = v86;
          v87 = v9->x2;
          if ( v85 >= v87 )
            v87 = (float)((float)((float)((float)((float)((float)((float)((float)(v64 - v61) * v77) + v61) - v79) * v77)
                                        + v79)
                                - v81)
                        * v77)
                + v81;
          v9->x2 = v87;
          v88 = v9->y2;
          if ( v83 >= v88 )
            v88 = v83;
          v9->y2 = v88;
        }
        v89 = v63[1];
        v90 = v59[1];
        v91 = *(float *)(v24 + 4);
        Scaleform::Render::Math2D::CubicCurveExtremum(v18, *(float *)(v24 + 4), v59[1], v63[1], &t1, &t2);
        v92 = t1;
        v93 = *(float *)&FLOAT_1_0;
        if ( t1 > 0.0 && t1 < 1.0 )
        {
          v94 = (float)((float)(v61 - v62) * t1) + v62;
          v95 = (float)((float)(v94 - (float)((float)((float)(v62 - v15) * t1) + v15)) * t1)
              + (float)((float)((float)(v62 - v15) * t1) + v15);
          v96 = (float)((float)((float)((float)((float)(v90 - v91) * t1) + v91)
                              - (float)((float)((float)(v91 - v18) * t1) + v18))
                      * t1)
              + (float)((float)((float)(v91 - v18) * t1) + v18);
          v97 = (float)((float)((float)((float)((float)((float)((float)((float)(v89 - v90) * t1) + v90)
                                                      - (float)((float)((float)(v90 - v91) * t1) + v91))
                                              * t1)
                                      + (float)((float)((float)(v90 - v91) * t1) + v91))
                              - v96)
                      * t1)
              + v96;
          v98 = v9->x1;
          v99 = (float)((float)((float)((float)((float)((float)((float)((float)(v64 - v61) * t1) + v61) - v94) * t1)
                                      + v94)
                              - v95)
                      * t1)
              + v95;
          if ( v9->x1 >= v99 )
            v98 = (float)((float)((float)((float)((float)((float)((float)((float)(v64 - v61) * t1) + v61) - v94) * t1)
                                        + v94)
                                - v95)
                        * t1)
                + v95;
          v9->x1 = v98;
          v100 = v9->y1;
          if ( v100 >= v97 )
            v100 = v97;
          v9->y1 = v100;
          v101 = v9->x2;
          if ( v99 >= v101 )
            v101 = (float)((float)((float)((float)((float)((float)((float)((float)(v64 - v61) * v92) + v61) - v94) * v92)
                                         + v94)
                                 - v95)
                         * v92)
                 + v95;
          v9->x2 = v101;
          v102 = v9->y2;
          if ( v97 >= v102 )
            v102 = v97;
          v9->y2 = v102;
          v93 = *(float *)&FLOAT_1_0;
        }
        v103 = t2;
        if ( t2 > 0.0 && t2 < v93 )
        {
          v104 = (float)((float)(v61 - v62) * t2) + v62;
          v105 = (float)((float)(v104 - (float)((float)((float)(v62 - v15) * t2) + v15)) * t2)
               + (float)((float)((float)(v62 - v15) * t2) + v15);
          v106 = (float)((float)((float)((float)((float)(v90 - v91) * t2) + v91)
                               - (float)((float)((float)(v91 - v18) * t2) + v18))
                       * t2)
               + (float)((float)((float)(v91 - v18) * t2) + v18);
          v107 = (float)((float)((float)((float)((float)((float)((float)((float)(v89 - v90) * t2) + v90)
                                                       - (float)((float)((float)(v90 - v91) * t2) + v91))
                                               * t2)
                                       + (float)((float)((float)(v90 - v91) * t2) + v91))
                               - v106)
                       * t2)
               + v106;
          v108 = v9->x1;
          v109 = (float)((float)((float)((float)((float)((float)((float)((float)(v64 - v61) * t2) + v61) - v104) * t2)
                                       + v104)
                               - v105)
                       * t2)
               + v105;
          if ( v9->x1 >= v109 )
            v108 = (float)((float)((float)((float)((float)((float)((float)((float)(v64 - v61) * t2) + v61) - v104) * t2)
                                         + v104)
                                 - v105)
                         * t2)
                 + v105;
          v9->x1 = v108;
          v110 = v9->y1;
          if ( v110 >= v107 )
            v110 = v107;
          v9->y1 = v110;
          v111 = v9->x2;
          if ( v109 >= v111 )
            v111 = (float)((float)((float)((float)((float)((float)((float)((float)(v64 - v61) * v103) + v61) - v104)
                                                 * v103)
                                         + v104)
                                 - v105)
                         * v103)
                 + v105;
          v9->x2 = v111;
          v112 = v9->y2;
          if ( v107 >= v112 )
            v112 = v107;
          v9->y2 = v112;
        }
        v113 = v9->x1;
        if ( v9->x1 >= v64 )
          v113 = v64;
        v114 = v9->y1;
        v9->x1 = v113;
        if ( v114 >= v89 )
          v114 = v89;
        v115 = v9->x2;
        v9->y1 = v114;
        if ( v64 >= v115 )
          v115 = v64;
        v9->x2 = v115;
        v53 = v9->y2;
        if ( v89 >= v53 )
          v53 = v89;
        v14 = *(float *)&FLOAT_1_0;
        v15 = v64;
        v13 = FLOAT_2_0;
        v18 = v89;
      }
      v9->y2 = v53;
    }
    while ( v19 < v128 );
    v10 = gen;
    v12 = (__int64)v129;
LABEL_113:
    v11 = v127 + 1;
    v127 = v11;
  }
  while ( v11 < LODWORD(v10->mStrokeSorter.OutPaths.Size) );
LABEL_114:
  v119 = v9->x2;
  v120 = v9;
  if ( v119 >= v9->x1 )
  {
    v121 = v9->y2;
    v122 = v9->y1;
    if ( v121 >= v122 )
    {
      v123 = v122 - (float)(scaledWidth * 0.5);
      v124 = v119 + (float)(scaledWidth * 0.5);
      v125 = v121 + (float)(scaledWidth * 0.5);
      v9->x1 = v9->x1 - (float)(scaledWidth * 0.5);
      v9->y1 = v123;
      v9->x2 = v124;
      v9->y2 = v125;
    }
  }
  return v120;
}idth * 0.5);
      v9->y1 = v123;
      v9->x2 = v124;
      v9->y2 = v125;
    }
  }
  return v120;
}

// File Line: 429
// RVA: 0x92AE10
Scaleform::Render::Rect<float> *__fastcall Scaleform::Render::ComputeBoundsSingleStroke<Scaleform::Render::Matrix2x4<float>>(Scaleform::Render::Rect<float> *result, Scaleform::Render::ShapeDataInterface *shape, Scaleform::Render::ShapePosInfo *pos, unsigned int strokeStyleIdx, Scaleform::Render::Matrix2x4<float> *trans, Scaleform::Render::StrokeGenerator *gen, Scaleform::Render::ToleranceParams *tol)
{
  unsigned int v7; // edi
  Scaleform::Render::ShapePosInfo *v8; // rsi
  Scaleform::Render::ShapeDataInterface *v9; // rbx
  Scaleform::Render::Rect<float> *v10; // r15
  float v11; // xmm1_4
  int v12; // ecx
  __m128 v13; // xmm1
  int v14; // ecx
  void (__fastcall ***v15)(_QWORD, signed __int64); // rcx
  Scaleform::Render::StrokerTypes::LineJoinType v16; // edx
  Scaleform::Render::StrokerTypes::LineCapType v17; // er10
  Scaleform::Render::StrokerTypes::LineCapType v18; // er8
  int v19; // eax
  unsigned int v20; // er12
  float v21; // xmm6_4
  float v22; // xmm7_4
  float v23; // xmm8_4
  float v24; // xmm9_4
  Scaleform::Render::VertexPath *v25; // rcx
  unsigned __int64 v26; // r15
  __int64 v27; // rdi
  unsigned int v28; // esi
  unsigned int v29; // ebx
  Scaleform::Render::StrokeSorter::PathType *v30; // rdx
  unsigned int v31; // eax
  int v32; // ecx
  Scaleform::Render::StrokeSorter::VertexType **v33; // r10
  Scaleform::Render::StrokeSorter::VertexType *v34; // r8
  char v35; // al
  unsigned int v36; // eax
  int v37; // ecx
  float *v38; // rdx
  unsigned int v39; // eax
  int v40; // ecx
  float *v41; // r9
  unsigned int v42; // ebx
  unsigned int v43; // eax
  int v44; // ecx
  float *v45; // rdx
  __int128 v46; // xmm2
  __int128 v47; // xmm1
  unsigned int v48; // edx
  unsigned __int64 v49; // r8
  unsigned __int64 v50; // rcx
  unsigned __int64 v51; // rax
  __int64 v52; // rcx
  Scaleform::Render::VertexBasic *v53; // rax
  float v54; // xmm0_4
  float v55; // xmm1_4
  void (__fastcall ***v56)(_QWORD, signed __int64); // rcx
  void (__fastcall ***v57)(_QWORD, signed __int64); // rcx
  float v59; // [rsp+60h] [rbp-98h]
  int v60; // [rsp+68h] [rbp-90h]
  float v61; // [rsp+6Ch] [rbp-8Ch]
  __int64 v62; // [rsp+78h] [rbp-80h]
  __int64 v63; // [rsp+80h] [rbp-78h]
  Scaleform::Render::Rect<float> *v64; // [rsp+100h] [rbp+8h]

  v64 = result;
  v7 = strokeStyleIdx;
  v8 = pos;
  v9 = shape;
  v10 = result;
  v62 = 0i64;
  v63 = 0i64;
  ((void (__fastcall *)(Scaleform::Render::ShapeDataInterface *, _QWORD, float *))shape->vfptr[5].__vecDelDtor)(
    shape,
    strokeStyleIdx,
    &v59);
  v11 = *(float *)&FLOAT_1_0;
  v12 = v60 & 6;
  if ( !(v60 & 6) )
  {
    v13 = (__m128)LODWORD(trans->M[1][1]);
    v13.m128_f32[0] = (float)((float)((float)(v13.m128_f32[0] + trans->M[1][0]) * 0.70710677)
                            * (float)((float)(v13.m128_f32[0] + trans->M[1][0]) * 0.70710677))
                    + (float)((float)((float)(trans->M[0][1] + trans->M[0][0]) * 0.70710677)
                            * (float)((float)(trans->M[0][1] + trans->M[0][0]) * 0.70710677));
    goto LABEL_7;
  }
  if ( v12 == 2 )
  {
    v13 = (__m128)LODWORD(trans->M[0][0]);
    v13.m128_f32[0] = (float)(v13.m128_f32[0] * v13.m128_f32[0]) + (float)(trans->M[1][0] * trans->M[1][0]);
    goto LABEL_7;
  }
  if ( v12 == 4 )
  {
    v13 = (__m128)LODWORD(trans->M[0][1]);
    v13.m128_f32[0] = (float)(v13.m128_f32[0] * v13.m128_f32[0]) + (float)(trans->M[1][1] * trans->M[1][1]);
LABEL_7:
    LODWORD(v11) = (unsigned __int128)_mm_sqrt_ps(v13);
  }
  v14 = v60 & 0x30;
  if ( v60 & 0x30 || v60 & 0xC0 )
  {
    v16 = 2;
    v17 = 2;
    v18 = 2;
    if ( v14 == 16 )
    {
      v16 = 3;
    }
    else if ( v14 == 32 )
    {
      v16 = 0;
    }
    if ( (v60 & 0xC0) == 64 )
    {
      v17 = 0;
    }
    else if ( (v60 & 0xC0) == 128 )
    {
      v17 = 1;
    }
    v19 = v60 & 0x300;
    if ( v19 == 256 )
    {
      v18 = 0;
    }
    else if ( v19 == 512 )
    {
      v18 = 1;
    }
    gen->mStroker.Width = (float)(v59 * v11) * 0.5;
    gen->mStroker.LineJoin = v16;
    gen->mStroker.StartLineCap = v17;
    gen->mStroker.EndLineCap = v18;
    gen->mStroker.MiterLimit = v61;
    gen->mStroker.CurveTolerance = tol->CurveTolerance;
    gen->mStroker.IntersectionEpsilon = tol->IntersectionEpsilon;
    Scaleform::Render::AddStrokeToSorter<Scaleform::Render::Matrix2x4<float>>(v9, v8, v7, trans);
    (*((void (__fastcall **)(Scaleform::Render::Stroker *))&gen->mStroker.vfptr->__vecDelDtor + 1))(&gen->mStroker);
    v20 = 0;
    v21 = *((float *)&_xmm_f149f2caf149f2ca7149f2ca7149f2ca + 3);
    v22 = *((float *)&_xmm_f149f2caf149f2ca7149f2ca7149f2ca + 2);
    v23 = *((float *)&_xmm_f149f2caf149f2ca7149f2ca7149f2ca + 1);
    v24 = *(float *)&_xmm_f149f2caf149f2ca7149f2ca7149f2ca;
    if ( LODWORD(gen->mStrokeSorter.OutPaths.Size) )
    {
      v25 = &gen->mPath;
      do
      {
        (*((void (__cdecl **)(Scaleform::Render::VertexPath *))&v25->vfptr->__vecDelDtor + 1))(v25);
        v26 = (unsigned __int64)v20 >> 4;
        v27 = v20 & 0xF;
        v28 = gen->mStrokeSorter.OutPaths.Pages[v26][v27].numVer & 0xFFFFFFF;
        v29 = 0;
        if ( v28 )
        {
          do
          {
            v30 = gen->mStrokeSorter.OutPaths.Pages[v26];
            v31 = v30[v27].numVer & 0xFFFFFFF;
            v32 = v29;
            if ( v29 >= v31 )
              v32 = v29 - v31;
            v33 = gen->mStrokeSorter.OutVertices.Pages;
            v34 = &v33[(unsigned __int64)(v32 + v30[v27].start) >> 4][((_BYTE)v32 + LOBYTE(v30[v27].start)) & 0xF];
            ++v29;
            v35 = v34->segType;
            if ( (unsigned __int8)v35 < 2u )
            {
              v46 = LODWORD(v34->y);
              v47 = LODWORD(v34->x);
              ((void (__fastcall *)(Scaleform::Render::Stroker *))gen->mStroker.vfptr->AddVertex)(&gen->mStroker);
            }
            else if ( v35 == 2 )
            {
              v36 = v30[v27].numVer & 0xFFFFFFF;
              v37 = v29;
              if ( v29 >= v36 )
                v37 = v29 - v36;
              v38 = &v33[(unsigned __int64)(v30[v27].start + v37) >> 4][(LOBYTE(v30[v27].start) + (_BYTE)v37) & 0xF].x;
              ++v29;
              Scaleform::Render::TessellateQuadCurve(
                (Scaleform::Render::TessBase *)&gen->mStroker.vfptr,
                tol,
                v34->x,
                v34->y,
                *v38,
                v38[1]);
            }
            else if ( v35 == 3 )
            {
              v39 = v30[v27].numVer & 0xFFFFFFF;
              v40 = v29;
              if ( v29 >= v39 )
                v40 = v29 - v39;
              v41 = &v33[(unsigned __int64)(v40 + v30[v27].start) >> 4][((_BYTE)v40 + LOBYTE(v30[v27].start)) & 0xF].x;
              v42 = v29 + 1;
              v43 = v30[v27].numVer & 0xFFFFFFF;
              v44 = v42;
              if ( v42 >= v43 )
                v44 = v42 - v43;
              v45 = &v33[(unsigned __int64)(v30[v27].start + v44) >> 4][(LOBYTE(v30[v27].start) + (_BYTE)v44) & 0xF].x;
              v29 = v42 + 1;
              Scaleform::Render::TessellateCubicCurve(
                (Scaleform::Render::TessBase *)&gen->mStroker.vfptr,
                tol,
                v34->x,
                v34->y,
                *v41,
                v41[1],
                *v45,
                v45[1]);
            }
          }
          while ( v29 < v28 );
        }
        Scaleform::Render::Stroker::GenerateStroke(&gen->mStroker, (Scaleform::Render::TessBase *)&gen->mPath.vfptr);
        v48 = 0;
        v49 = gen->mPath.Vertices.Size;
        if ( v49 )
        {
          v50 = 0i64;
          do
          {
            v51 = v50 >> 4;
            v52 = v50 & 0xF;
            v53 = gen->mPath.Vertices.Pages[v51];
            v54 = v53[v52].y;
            v55 = v53[v52].x;
            if ( v24 >= v55 )
              v24 = v53[v52].x;
            if ( v23 >= v54 )
              v23 = v53[v52].y;
            if ( v55 >= v22 )
              v22 = v53[v52].x;
            if ( v54 >= v21 )
              v21 = v53[v52].y;
            v50 = ++v48;
          }
          while ( v48 < v49 );
        }
        ++v20;
        v25 = &gen->mPath;
      }
      while ( v20 < LODWORD(gen->mStrokeSorter.OutPaths.Size) );
      v10 = v64;
    }
    v10->x1 = v24;
    v10->y1 = v23;
    v10->x2 = v22;
    v10->y2 = v21;
    v56 = (void (__fastcall ***)(_QWORD, signed __int64))v63;
    if ( v63 && !_InterlockedDecrement((volatile signed __int32 *)(v63 + 8)) && v56 )
      (**v56)(v56, 1i64);
  }
  else
  {
    Scaleform::Render::ComputeBoundsRoundStrokeSorter<Scaleform::Render::Matrix2x4<float>>(
      v10,
      v9,
      v8,
      v7,
      trans,
      v59 * v11,
      gen);
    v15 = (void (__fastcall ***)(_QWORD, signed __int64))v63;
    if ( v63 && !_InterlockedDecrement((volatile signed __int32 *)(v63 + 8)) && v15 )
      (**v15)(v15, 1i64);
  }
  v57 = (void (__fastcall ***)(_QWORD, signed __int64))v62;
  if ( v62 && !_InterlockedDecrement((volatile signed __int32 *)(v62 + 8)) && v57 )
    (**v57)(v57, 1i64);
  return v10;
}

// File Line: 532
// RVA: 0x92B720
void __fastcall Scaleform::Render::ExpandBoundsToLayerStrokes<Scaleform::Render::Matrix2x4<float>>(Scaleform::Render::ShapeDataInterface *shape, Scaleform::Render::ShapePosInfo *pos, Scaleform::Render::Matrix2x4<float> *trans, Scaleform::Render::StrokeGenerator *gen)
{
  Scaleform::Render::StrokeGenerator *v4; // r14
  Scaleform::Render::Matrix2x4<float> *v5; // r15
  Scaleform::Render::ShapePosInfo *v6; // rsi
  Scaleform::Render::ShapeDataInterface *v7; // r12
  Scaleform::MemoryHeap *v8; // rax
  char v9; // bl
  int v10; // ST14_4
  int v11; // ST18_4
  unsigned int v12; // ST1C_4
  int v13; // eax
  float *v14; // rdi
  Scaleform::Render::ToleranceParams *v15; // r13
  float v16; // xmm6_4
  float v17; // xmm0_4
  float v18; // xmm5_4
  float v19; // xmm4_4
  float v20; // xmm1_4
  float v21; // xmm2_4
  float v22; // xmm3_4
  float v23; // xmm0_4
  unsigned __int64 v24; // r14
  __int64 v25; // r15
  unsigned int v26; // ebx
  __int64 v27; // rax
  int *v28; // rax
  __int64 v29; // rax
  int v30; // ST14_4
  int v31; // ST18_4
  unsigned int v32; // ST1C_4
  int v33; // [rsp+14h] [rbp-7Dh]
  __int64 v34; // [rsp+18h] [rbp-79h]
  Scaleform::Render::Matrix2x4<float> *transa; // [rsp+20h] [rbp-71h]
  Scaleform::Render::StrokeGenerator *gena; // [rsp+28h] [rbp-69h]
  Scaleform::Render::ToleranceParams *v37; // [rsp+30h] [rbp-61h]
  float v38; // [rsp+38h] [rbp-59h]
  int v39; // [rsp+3Ch] [rbp-55h]
  Scaleform::Render::ShapePosInfo posa; // [rsp+40h] [rbp-51h]
  __int64 v41; // [rsp+78h] [rbp-19h]
  char v42; // [rsp+80h] [rbp-11h]
  Scaleform::Render::Matrix2x4<float> *v43; // [rsp+F8h] [rbp+67h]
  Scaleform::Render::StrokeGenerator *v44; // [rsp+100h] [rbp+6Fh]
  Scaleform::Render::ToleranceParams *v45; // [rsp+108h] [rbp+77h]
  float *vars0; // [rsp+110h] [rbp+7Fh]

  v41 = -2i64;
  v4 = gen;
  v5 = trans;
  v6 = pos;
  v7 = shape;
  v8 = gen->Heap1.pHeap;
  *(_QWORD *)&posa.Pos = 32i64;
  *(_QWORD *)&posa.StartY = (char *)&posa + 4;
  *(_QWORD *)&posa.LastY = v8;
  v9 = 1;
  *(_QWORD *)&posa.Pos = pos->Pos;
  posa.StartX = pos->StartX;
  posa.StartY = pos->StartY;
  v10 = pos->LastX;
  v11 = pos->LastY;
  v12 = pos->FillBase;
  transa = *(Scaleform::Render::Matrix2x4<float> **)&pos->StrokeBase;
  gena = *(Scaleform::Render::StrokeGenerator **)&pos->NumStrokeBits;
  v37 = *(Scaleform::Render::ToleranceParams **)&pos->Fill1;
  v38 = pos->Sfactor;
  v39 = *(_DWORD *)&pos->Initialized;
  v13 = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, Scaleform::Render::ShapePosInfo *, char *, unsigned int *))v7->vfptr[8].__vecDelDtor)(
          v7,
          pos,
          &v42,
          &posa.StrokeBase);
  if ( v13 )
  {
    v14 = vars0;
    v15 = v45;
    do
    {
      if ( v13 == 2 && !v9 )
        break;
      if ( posa.NumStrokeBits
        && (posa.NumStrokeBits >= posa.Pos
         || !(*(_DWORD *)(*(_QWORD *)&posa.StartY + 4 * ((unsigned __int64)posa.NumStrokeBits >> 5)) & (1 << (posa.NumStrokeBits & 0x1F)))) )
      {
        Scaleform::Render::ComputeBoundsSingleStroke<Scaleform::Render::Matrix2x4<float>>(
          (Scaleform::Render::Rect<float> *)&posa.Fill1,
          v7,
          &posa,
          posa.NumStrokeBits,
          v5,
          v4,
          v15);
        v16 = posa.Sfactor;
        v17 = *(float *)&posa.Fill1;
        if ( posa.Sfactor >= *(float *)&posa.Fill1 )
        {
          v18 = *(float *)&posa.Initialized;
          v19 = *(float *)&posa.Stroke;
          if ( *(float *)&posa.Initialized >= *(float *)&posa.Stroke )
          {
            v20 = *v14;
            if ( *v14 >= *(float *)&posa.Fill1 )
              v20 = *(float *)&posa.Fill1;
            *v14 = v20;
            v21 = v14[1];
            if ( v21 >= v19 )
              v21 = v19;
            v14[1] = v21;
            v22 = v14[2];
            if ( v17 >= v22 )
              v22 = v17;
            v14[2] = v22;
            v23 = v14[3];
            if ( v19 >= v23 )
              v23 = v19;
            v14[3] = v23;
            if ( v20 >= v16 )
              v20 = v16;
            *v14 = v20;
            if ( v21 >= v18 )
              v21 = v18;
            v14[1] = v21;
            if ( v16 >= v22 )
              v22 = v16;
            v14[2] = v22;
            if ( v18 >= v23 )
              v23 = v18;
            v14[3] = v23;
          }
        }
        v24 = posa.NumStrokeBits;
        if ( posa.NumStrokeBits >= posa.Pos )
        {
          v25 = (posa.Pos + 31) >> 5;
          v26 = (posa.NumStrokeBits + 32) >> 5;
          if ( v26 < 2 * (signed int)v25 )
            v26 = 2 * v25;
          if ( v26 > (unsigned int)v25 )
          {
            v27 = **(_QWORD **)&posa.LastY;
            if ( *(Scaleform::Render::ShapePosInfo **)&posa.StartY == (Scaleform::Render::ShapePosInfo *)&posa.StartX )
            {
              v28 = (int *)(*(__int64 (__fastcall **)(_QWORD, signed __int64, _QWORD))(v27 + 80))(
                             *(_QWORD *)&posa.LastY,
                             4i64 * v26,
                             0i64);
              *(_QWORD *)&posa.StartY = v28;
              *v28 = posa.StartX;
              v29 = *(_QWORD *)&posa.StartY;
            }
            else
            {
              v29 = (*(__int64 (__fastcall **)(_QWORD, _QWORD, signed __int64))(v27 + 88))(
                      *(_QWORD *)&posa.LastY,
                      *(_QWORD *)&posa.StartY,
                      4i64 * v26);
              *(_QWORD *)&posa.StartY = v29;
            }
            memset((void *)(v29 + 4 * v25), 0, 4i64 * (v26 - (unsigned int)v25));
            posa.Pos = 32 * v26;
          }
        }
        *(_DWORD *)(*(_QWORD *)&posa.StartY + 4 * (v24 >> 5)) |= 1 << (v24 & 0x1F);
        v4 = v44;
        v5 = v43;
      }
      v7->vfptr[10].__vecDelDtor((Scaleform::RefCountImplCore *)&v7->vfptr, (unsigned int)v6);
      v9 = 0;
      posa.Pos = v6->Pos;
      posa.StartX = v6->StartX;
      posa.StartY = v6->StartY;
      v30 = v6->LastX;
      v31 = v6->LastY;
      v32 = v6->FillBase;
      transa = *(Scaleform::Render::Matrix2x4<float> **)&v6->StrokeBase;
      gena = *(Scaleform::Render::StrokeGenerator **)&v6->NumStrokeBits;
      v37 = *(Scaleform::Render::ToleranceParams **)&v6->Fill1;
      v38 = v6->Sfactor;
      v39 = *(_DWORD *)&v6->Initialized;
      v13 = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, Scaleform::Render::ShapePosInfo *, char *, unsigned int *))v7->vfptr[8].__vecDelDtor)(
              v7,
              v6,
              &v42,
              &posa.StrokeBase);
    }
    while ( v13 );
  }
  v6->Pos = posa.Pos;
  v6->StartX = posa.StartX;
  v6->StartY = posa.StartY;
  v6->LastX = v33;
  *(_QWORD *)&v6->LastY = v34;
  *(_QWORD *)&v6->StrokeBase = transa;
  *(_QWORD *)&v6->NumStrokeBits = gena;
  *(_QWORD *)&v6->Fill1 = v37;
  v6->Sfactor = v38;
  *(_DWORD *)&v6->Initialized = v39;
  if ( *(Scaleform::Render::ShapePosInfo **)&posa.StartY != (Scaleform::Render::ShapePosInfo *)&posa.StartX )
    (*(void (**)(void))(**(_QWORD **)&posa.LastY + 96i64))();
}

// File Line: 580
// RVA: 0x92BB50
void __fastcall Scaleform::Render::ExpandBoundsToStrokes<Scaleform::Render::Matrix2x4<float>>(Scaleform::Render::ShapeDataInterface *shape, Scaleform::Render::Matrix2x4<float> *trans, Scaleform::Render::StrokeGenerator *gen, Scaleform::Render::ToleranceParams *tol, Scaleform::Render::Rect<float> *bounds)
{
  Scaleform::Render::ToleranceParams *v5; // rsi
  Scaleform::Render::StrokeGenerator *v6; // r14
  Scaleform::Render::Matrix2x4<float> *v7; // r15
  Scaleform::Render::ShapeDataInterface *v8; // rbx
  __int64 v9; // r12
  __int64 v10; // r13
  Scaleform::Render::ShapePosInfo pos; // [rsp+30h] [rbp-51h]
  __int64 v12; // [rsp+68h] [rbp-19h]
  __int128 v13; // [rsp+70h] [rbp-11h]
  __int64 v14; // [rsp+80h] [rbp-1h]
  char v15; // [rsp+88h] [rbp+7h]
  char v16; // [rsp+98h] [rbp+17h]
  __int64 v17; // [rsp+E0h] [rbp+5Fh]

  v5 = tol;
  v6 = gen;
  v7 = trans;
  v8 = shape;
  pos.Pos = ((__int64 (*)(void))shape->vfptr[6].__vecDelDtor)();
  LODWORD(pos.Sfactor) = (_DWORD)FLOAT_1_0;
  *(_QWORD *)&pos.StartX = 0i64;
  v9 = pos.Pos;
  *(_QWORD *)&pos.LastX = 0i64;
  v10 = 0i64;
  *(_QWORD *)&pos.FillBase = 0i64;
  *(_QWORD *)&pos.NumFillBits = 0i64;
  *(_QWORD *)&pos.Fill0 = 0i64;
  pos.Stroke = 0;
  pos.Initialized = 0;
  v17 = 0i64;
  v13 = 0ui64;
  v14 = 0i64;
  v12 = *(_QWORD *)&pos.Sfactor;
  if ( ((unsigned int (__fastcall *)(Scaleform::Render::ShapeDataInterface *, Scaleform::Render::ShapePosInfo *, char *, char *))v8->vfptr[8].__vecDelDtor)(
         v8,
         &pos,
         &v16,
         &v15) )
  {
    do
    {
      *(_QWORD *)&pos.LastY = v17;
      *(_OWORD *)&pos.StrokeBase = v13;
      *(_QWORD *)&pos.Fill1 = v14;
      *(_QWORD *)&pos.Pos = v9;
      *(_QWORD *)&pos.StartY = v10;
      *(_QWORD *)&pos.Sfactor = v12;
      Scaleform::Render::ExpandBoundsToLayerStrokes<Scaleform::Render::Matrix2x4<float>>(v8, &pos, v7, v6);
      v9 = *(_QWORD *)&pos.Pos;
      v10 = *(_QWORD *)&pos.StartY;
      v17 = *(_QWORD *)&pos.LastY;
      v13 = *(_OWORD *)&pos.StrokeBase;
      v14 = *(_QWORD *)&pos.Fill1;
      v12 = *(_QWORD *)&pos.Sfactor;
    }
    while ( ((unsigned int (__fastcall *)(Scaleform::Render::ShapeDataInterface *, Scaleform::Render::ShapePosInfo *, char *, char *, Scaleform::Render::ToleranceParams *, Scaleform::Render::Rect<float> *))v8->vfptr[8].__vecDelDtor)(
              v8,
              &pos,
              &v16,
              &v15,
              v5,
              bounds) );
  }
}

