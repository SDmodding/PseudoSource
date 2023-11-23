// File Line: 84
// RVA: 0x881DF0
void __fastcall Scaleform::Render::ExpandBoundsToPath<Scaleform::Render::Matrix2x4<float>>(
        Scaleform::Render::ShapeDataInterface *shape,
        Scaleform::Render::Matrix2x4<float> *trans,
        Scaleform::Render::ShapePosInfo *pos,
        float *coord,
        Scaleform::Render::Rect<float> *bounds)
{
  float v5; // xmm2_4
  float v6; // xmm3_4
  Scaleform::Render::Rect<float> *v7; // rbx
  float v12; // xmm3_4
  float v13; // xmm0_4
  float x1; // xmm1_4
  float y1; // xmm1_4
  float x2; // xmm2_4
  float y2; // xmm0_4
  Scaleform::RefCountImplCoreVtbl *vfptr; // rax
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
  float v70; // xmm3_4
  float v71; // xmm1_4
  float v72; // xmm6_4
  float v73; // xmm4_4
  float v74; // xmm7_4
  float v75; // xmm2_4
  float v76; // xmm0_4
  float v77; // xmm0_4
  float v78; // xmm0_4
  float v79; // xmm0_4
  float v80; // xmm4_4
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
  float v94; // xmm2_4
  float v95; // xmm5_4
  float v96; // xmm3_4
  float v97; // xmm4_4
  float v98; // xmm7_4
  float v99; // xmm0_4
  float v100; // xmm1_4
  float v101; // xmm0_4
  float v102; // xmm0_4
  float v103; // xmm0_4
  float v104; // xmm4_4
  float v105; // xmm2_4
  float v106; // xmm7_4
  float v107; // xmm4_4
  float v108; // xmm5_4
  float v109; // xmm1_4
  float v110; // xmm0_4
  float v111; // xmm2_4
  float v112; // xmm0_4
  float v113; // xmm0_4
  float v114; // xmm0_4
  float v115; // xmm0_4
  float v116; // xmm2_4
  float v117; // xmm1_4
  float v118; // xmm3_4
  float v119; // xmm2_4
  float v120; // xmm0_4
  float t2; // [rsp+F0h] [rbp+8h] BYREF

  v5 = *coord;
  v6 = coord[1];
  v7 = bounds;
  *coord = (float)((float)(*coord * trans->M[0][0]) + (float)(v6 * trans->M[0][1])) + trans->M[0][3];
  v12 = (float)((float)(v6 * trans->M[1][1]) + (float)(v5 * trans->M[1][0])) + trans->M[1][3];
  coord[1] = v12;
  v13 = *coord;
  x1 = v7->x1;
  if ( v7->x1 >= *coord )
    x1 = *coord;
  v7->x1 = x1;
  y1 = v7->y1;
  if ( y1 >= v12 )
    y1 = v12;
  x2 = v7->x2;
  v7->y1 = y1;
  if ( v13 >= x2 )
    x2 = v13;
  y2 = v7->y2;
  v7->x2 = x2;
  if ( v12 >= y2 )
    y2 = v12;
  vfptr = shape->vfptr;
  v7->y2 = y2;
  v19 = *coord;
  v20 = coord[1];
  for ( i = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, Scaleform::Render::ShapePosInfo *, float *))vfptr[9].__vecDelDtor)(
              shape,
              pos,
              coord);
        i;
        i = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, Scaleform::Render::ShapePosInfo *, float *))shape->vfptr[9].__vecDelDtor)(
              shape,
              pos,
              coord) )
  {
    switch ( i )
    {
      case 1:
        v22 = *coord;
        v23 = coord[1];
        *coord = (float)((float)(*coord * trans->M[0][0]) + (float)(v23 * trans->M[0][1])) + trans->M[0][3];
        v24 = (float)((float)(v23 * trans->M[1][1]) + (float)(v22 * trans->M[1][0])) + trans->M[1][3];
        coord[1] = v24;
        v25 = *coord;
        v26 = v7->x1;
        if ( v7->x1 >= *coord )
          v26 = *coord;
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
        v19 = *coord;
        v20 = coord[1];
        break;
      case 2:
        v30 = *coord;
        v31 = coord[1];
        *coord = (float)((float)(v31 * trans->M[0][1]) + (float)(*coord * trans->M[0][0])) + trans->M[0][3];
        coord[1] = (float)((float)(v31 * trans->M[1][1]) + (float)(v30 * trans->M[1][0])) + trans->M[1][3];
        v32 = coord[2];
        v33 = coord[3];
        coord[2] = (float)((float)(v33 * trans->M[0][1]) + (float)(v32 * trans->M[0][0])) + trans->M[0][3];
        v34 = (float)((float)(v33 * trans->M[1][1]) + (float)(v32 * trans->M[1][0])) + trans->M[1][3];
        coord[3] = v34;
        v35 = *coord;
        v36 = coord[2];
        v37 = (float)((float)(*coord * 2.0) - v19) - v36;
        if ( v37 != 0.0 )
        {
          v38 = (float)(v35 - v19) / v37;
          if ( v38 > 0.0 && v38 < 1.0 )
          {
            v39 = (float)((float)((float)((float)((float)(v34 - coord[1]) * v38) + coord[1])
                                - (float)((float)((float)(coord[1] - v20) * v38) + v20))
                        * v38)
                + (float)((float)((float)(coord[1] - v20) * v38) + v20);
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
        v45 = coord[1];
        v46 = coord[3];
        v47 = (float)((float)(v45 * 2.0) - v20) - v46;
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
            v51 = (float)((float)((float)((float)((float)(coord[2] - *coord) * v48) + *coord)
                                - (float)((float)((float)(*coord - v19) * v48) + v19))
                        * v48)
                + (float)((float)((float)(*coord - v19) * v48) + v19);
            if ( v7->x1 >= v51 )
              v50 = (float)((float)((float)((float)((float)(coord[2] - *coord) * v48) + *coord)
                                  - (float)((float)((float)(*coord - v19) * v48) + v19))
                          * v48)
                  + (float)((float)((float)(*coord - v19) * v48) + v19);
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
        v55 = coord[2];
        v56 = v7->x1;
        v57 = coord[3];
        if ( v7->x1 >= v55 )
          v56 = coord[2];
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
        v19 = coord[2];
        v20 = coord[3];
        break;
      case 3:
        v61 = *coord;
        v62 = coord[1];
        *coord = (float)((float)(v62 * trans->M[0][1]) + (float)(*coord * trans->M[0][0])) + trans->M[0][3];
        coord[1] = (float)((float)(v62 * trans->M[1][1]) + (float)(v61 * trans->M[1][0])) + trans->M[1][3];
        v63 = coord[3];
        v64 = coord[2];
        coord[2] = (float)((float)(v63 * trans->M[0][1]) + (float)(v64 * trans->M[0][0])) + trans->M[0][3];
        v65 = (float)((float)(v63 * trans->M[1][1]) + (float)(v64 * trans->M[1][0])) + trans->M[1][3];
        coord[3] = v65;
        v66 = coord[4];
        coord[3] = (float)((float)(v66 * trans->M[0][1]) + (float)(v65 * trans->M[0][0])) + trans->M[0][3];
        v67 = (float)((float)(v66 * trans->M[1][1]) + (float)(v65 * trans->M[1][0])) + trans->M[1][3];
        coord[4] = v67;
        v68 = coord[2];
        v69 = *coord;
        Scaleform::Render::Math2D::CubicCurveExtremum(v19, *coord, v68, v67, (float *)&bounds, &t2);
        if ( *(float *)&bounds > 0.0 && *(float *)&bounds < 1.0 )
        {
          v70 = coord[1];
          v71 = (float)((float)(coord[3] - v70) * *(float *)&bounds) + v70;
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
          v75 = (float)((float)((float)((float)((float)((float)((float)((float)(coord[5] - coord[3]) * *(float *)&bounds)
                                                              + coord[3])
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
          v80 = coord[1];
          v81 = (float)((float)(coord[3] - v80) * t2) + v80;
          v82 = (float)((float)(coord[2] - *coord) * t2) + *coord;
          v83 = (float)((float)(v80 - v20) * t2) + v20;
          v84 = (float)((float)(v82 - (float)((float)((float)(*coord - v19) * t2) + v19)) * t2)
              + (float)((float)((float)(*coord - v19) * t2) + v19);
          v85 = (float)((float)((float)((float)((float)((float)((float)((float)(coord[5] - coord[3]) * t2) + coord[3])
                                                      - v81)
                                              * t2)
                                      + v81)
                              - (float)((float)((float)(v81 - v83) * t2) + v83))
                      * t2)
              + (float)((float)((float)(v81 - v83) * t2) + v83);
          v86 = v7->x1;
          v87 = (float)((float)((float)((float)((float)((float)((float)((float)(coord[4] - coord[2]) * t2) + coord[2])
                                                      - v82)
                                              * t2)
                                      + v82)
                              - v84)
                      * t2)
              + v84;
          if ( v7->x1 >= v87 )
            v86 = (float)((float)((float)((float)((float)((float)((float)((float)(coord[4] - coord[2]) * t2) + coord[2])
                                                        - v82)
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
        v91 = coord[5];
        v92 = coord[3];
        v93 = coord[1];
        Scaleform::Render::Math2D::CubicCurveExtremum(v20, v93, v92, v91, (float *)&bounds, &t2);
        if ( *(float *)&bounds > 0.0 && *(float *)&bounds < 1.0 )
        {
          v94 = *coord;
          v95 = (float)((float)(coord[2] - v94) * *(float *)&bounds) + v94;
          v96 = (float)((float)(v93 - v20) * *(float *)&bounds) + v20;
          v97 = (float)((float)(v95 - (float)((float)((float)(v94 - v19) * *(float *)&bounds) + v19)) * *(float *)&bounds)
              + (float)((float)((float)(v94 - v19) * *(float *)&bounds) + v19);
          v98 = (float)((float)((float)((float)((float)((float)((float)((float)(v91 - v92) * *(float *)&bounds) + v92)
                                                      - (float)((float)((float)(v92 - v93) * *(float *)&bounds) + v93))
                                              * *(float *)&bounds)
                                      + (float)((float)((float)(v92 - v93) * *(float *)&bounds) + v93))
                              - (float)((float)((float)((float)((float)((float)(v92 - v93) * *(float *)&bounds) + v93)
                                                      - v96)
                                              * *(float *)&bounds)
                                      + v96))
                      * *(float *)&bounds)
              + (float)((float)((float)((float)((float)((float)(v92 - v93) * *(float *)&bounds) + v93) - v96)
                              * *(float *)&bounds)
                      + v96);
          v99 = v7->x1;
          v100 = (float)((float)((float)((float)((float)((float)((float)((float)(coord[4] - coord[2]) * *(float *)&bounds)
                                                               + coord[2])
                                                       - v95)
                                               * *(float *)&bounds)
                                       + v95)
                               - v97)
                       * *(float *)&bounds)
               + v97;
          if ( v7->x1 >= v100 )
            v99 = (float)((float)((float)((float)((float)((float)((float)((float)(coord[4] - coord[2])
                                                                        * *(float *)&bounds)
                                                                + coord[2])
                                                        - v95)
                                                * *(float *)&bounds)
                                        + v95)
                                - v97)
                        * *(float *)&bounds)
                + v97;
          v7->x1 = v99;
          v101 = v7->y1;
          if ( v101 >= v98 )
            v101 = v98;
          v7->y1 = v101;
          v102 = v7->x2;
          if ( v100 >= v102 )
            v102 = v100;
          v7->x2 = v102;
          v103 = v7->y2;
          if ( v98 >= v103 )
            v103 = v98;
          v7->y2 = v103;
        }
        if ( t2 > 0.0 && t2 < 1.0 )
        {
          v104 = coord[1];
          v105 = (float)((float)(coord[3] - v104) * t2) + v104;
          v106 = (float)((float)(coord[2] - *coord) * t2) + *coord;
          v107 = (float)((float)(v104 - v20) * t2) + v20;
          v108 = (float)((float)(v106 - (float)((float)((float)(*coord - v19) * t2) + v19)) * t2)
               + (float)((float)((float)(*coord - v19) * t2) + v19);
          v109 = (float)((float)((float)((float)((float)((float)((float)((float)(coord[5] - coord[3]) * t2) + coord[3])
                                                       - v105)
                                               * t2)
                                       + v105)
                               - (float)((float)((float)(v105 - v107) * t2) + v107))
                       * t2)
               + (float)((float)((float)(v105 - v107) * t2) + v107);
          v110 = v7->x1;
          v111 = (float)((float)((float)((float)((float)((float)((float)((float)(coord[4] - coord[2]) * t2) + coord[2])
                                                       - v106)
                                               * t2)
                                       + v106)
                               - v108)
                       * t2)
               + v108;
          if ( v7->x1 >= v111 )
            v110 = (float)((float)((float)((float)((float)((float)((float)((float)(coord[4] - coord[2]) * t2) + coord[2])
                                                         - v106)
                                                 * t2)
                                         + v106)
                                 - v108)
                         * t2)
                 + v108;
          v7->x1 = v110;
          v112 = v7->y1;
          if ( v112 >= v109 )
            v112 = v109;
          v7->y1 = v112;
          v113 = v7->x2;
          if ( v111 >= v113 )
            v113 = v111;
          v7->x2 = v113;
          v114 = v7->y2;
          if ( v109 >= v114 )
            v114 = v109;
          v7->y2 = v114;
        }
        v115 = coord[4];
        v116 = v7->x1;
        v117 = coord[5];
        if ( v7->x1 >= v115 )
          v116 = coord[4];
        v118 = v7->y1;
        v7->x1 = v116;
        if ( v118 >= v117 )
          v118 = v117;
        v119 = v7->x2;
        v7->y1 = v118;
        if ( v115 >= v119 )
          v119 = v115;
        v120 = v7->y2;
        v7->x2 = v119;
        if ( v117 >= v120 )
          v120 = v117;
        v7->y2 = v120;
        v19 = coord[4];
        v20 = coord[5];
        break;
    }
  }
}

// File Line: 195
// RVA: 0x881CE0
void __fastcall Scaleform::Render::ExpandBoundsToFill<Scaleform::Render::Matrix2x4<float>>(
        Scaleform::Render::ShapeDataInterface *shape,
        Scaleform::Render::Matrix2x4<float> *trans,
        Scaleform::Render::Rect<float> *bounds,
        Scaleform::Render::BoundEdges edgesToCheck)
{
  Scaleform::RefCountImplCoreVtbl *vfptr; // rax
  bool v9; // zf
  int v10; // [rsp+30h] [rbp-19h] BYREF
  int v11; // [rsp+34h] [rbp-15h]
  float coord[6]; // [rsp+40h] [rbp-9h] BYREF
  Scaleform::Render::ShapePosInfo pos; // [rsp+58h] [rbp+Fh] BYREF

  pos.Pos = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *))shape->vfptr[6].__vecDelDtor)(shape);
  LODWORD(pos.Sfactor) = (_DWORD)FLOAT_1_0;
  vfptr = shape->vfptr;
  memset(&pos.StartX, 0, 44);
  pos.Initialized = 0;
  if ( ((unsigned int (__fastcall *)(Scaleform::Render::ShapeDataInterface *, Scaleform::Render::ShapePosInfo *, float *, int *))vfptr[8].__vecDelDtor)(
         shape,
         &pos,
         coord,
         &v10) )
  {
    do
    {
      if ( edgesToCheck )
      {
        if ( edgesToCheck != Bound_FillEdges )
        {
          if ( edgesToCheck == Bound_AllEdges )
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
        Scaleform::Render::ExpandBoundsToPath<Scaleform::Render::Matrix2x4<float>>(shape, trans, &pos, coord, bounds);
        continue;
      }
LABEL_5:
      shape->vfptr[10].__vecDelDtor(shape, (unsigned int)&pos);
    }
    while ( ((unsigned int (__fastcall *)(Scaleform::Render::ShapeDataInterface *, Scaleform::Render::ShapePosInfo *, float *, int *))shape->vfptr[8].__vecDelDtor)(
              shape,
              &pos,
              coord,
              &v10) );
  }
}

// File Line: 242
// RVA: 0x92A110
Scaleform::Render::Rect<float> *__fastcall Scaleform::Render::ComputeBoundsRoundStroke<Scaleform::Render::Matrix2x4<float>>(
        Scaleform::Render::Rect<float> *result,
        Scaleform::Render::ShapeDataInterface *shape,
        Scaleform::Render::Matrix2x4<float> *trans,
        Scaleform::Render::ShapePosInfo *pos,
        float *coord,
        unsigned int *styles)
{
  unsigned int v10; // xmm0_4
  int v11; // eax
  __m128 v12; // xmm1
  __m128 v13; // xmm1
  __m128 v14; // xmm2
  float v15; // xmm6_4
  float x2; // xmm3_4
  float y2; // xmm1_4
  float y1; // xmm0_4
  float v19; // xmm6_4
  void (__fastcall ***v20)(_QWORD, __int64); // rcx
  void (__fastcall ***v21)(_QWORD, __int64); // rcx
  float v23; // [rsp+38h] [rbp-40h] BYREF
  int v24; // [rsp+40h] [rbp-38h]
  __int64 v25; // [rsp+50h] [rbp-28h]
  __int64 v26; // [rsp+58h] [rbp-20h]

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
  v10 = (unsigned int)FLOAT_1_0;
  v11 = v24 & 6;
  if ( (v24 & 6) != 0 )
  {
    if ( v11 == 2 )
    {
      v13 = (__m128)LODWORD(trans->M[0][0]);
      v13.m128_f32[0] = (float)(v13.m128_f32[0] * v13.m128_f32[0]) + (float)(trans->M[1][0] * trans->M[1][0]);
      v10 = _mm_sqrt_ps(v13).m128_u32[0];
    }
    else if ( v11 == 4 )
    {
      v12 = (__m128)LODWORD(trans->M[0][1]);
      v12.m128_f32[0] = (float)(v12.m128_f32[0] * v12.m128_f32[0]) + (float)(trans->M[1][1] * trans->M[1][1]);
      v10 = _mm_sqrt_ps(v12).m128_u32[0];
    }
  }
  else
  {
    v14 = (__m128)LODWORD(trans->M[0][1]);
    v14.m128_f32[0] = (float)((float)((float)(v14.m128_f32[0] + trans->M[0][0]) * 0.70710677)
                            * (float)((float)(v14.m128_f32[0] + trans->M[0][0]) * 0.70710677))
                    + (float)((float)((float)(trans->M[1][1] + trans->M[1][0]) * 0.70710677)
                            * (float)((float)(trans->M[1][1] + trans->M[1][0]) * 0.70710677));
    v10 = _mm_sqrt_ps(v14).m128_u32[0];
  }
  v15 = v23 * *(float *)&v10;
  Scaleform::Render::ExpandBoundsToPath<Scaleform::Render::Matrix2x4<float>>(shape, trans, pos, coord, result);
  x2 = result->x2;
  if ( x2 >= result->x1 )
  {
    y2 = result->y2;
    y1 = result->y1;
    if ( y2 >= y1 )
    {
      v19 = v15 * 0.5;
      result->x1 = result->x1 - v19;
      result->y1 = y1 - v19;
      result->x2 = x2 + v19;
      result->y2 = y2 + v19;
    }
  }
  v20 = (void (__fastcall ***)(_QWORD, __int64))v26;
  if ( v26 && !_InterlockedDecrement((volatile signed __int32 *)(v26 + 8)) && v20 )
    (**v20)(v20, 1i64);
  v21 = (void (__fastcall ***)(_QWORD, __int64))v25;
  if ( v25 && !_InterlockedDecrement((volatile signed __int32 *)(v25 + 8)) && v21 )
    (**v21)(v21, 1i64);
  return result;
}

// File Line: 277
// RVA: 0x92BCD0
void __fastcall Scaleform::Render::ExpandBoundsToStrokesSimplified<Scaleform::Render::Matrix2x4<float>>(
        Scaleform::Render::ShapeDataInterface *shape,
        Scaleform::Render::Matrix2x4<float> *trans,
        Scaleform::Render::Rect<float> *bounds)
{
  unsigned int v6; // eax
  float x2; // xmm6_4
  float x1; // xmm0_4
  float y2; // xmm5_4
  float y1; // xmm2_4
  float v11; // xmm1_4
  float v12; // xmm3_4
  float v13; // xmm4_4
  float v14; // xmm0_4
  unsigned int styles[4]; // [rsp+30h] [rbp-29h] BYREF
  Scaleform::Render::Rect<float> result; // [rsp+40h] [rbp-19h] BYREF
  float coord[6]; // [rsp+50h] [rbp-9h] BYREF
  Scaleform::Render::ShapePosInfo pos; // [rsp+68h] [rbp+Fh] BYREF

  v6 = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *))shape->vfptr[6].__vecDelDtor)(shape);
  LODWORD(pos.Sfactor) = (_DWORD)FLOAT_1_0;
  pos.Pos = v6;
  memset(&pos.StartX, 0, 44);
  pos.Initialized = 0;
  while ( ((unsigned int (__fastcall *)(Scaleform::Render::ShapeDataInterface *, Scaleform::Render::ShapePosInfo *, float *, unsigned int *))shape->vfptr[8].__vecDelDtor)(
            shape,
            &pos,
            coord,
            styles) )
  {
    if ( styles[2] )
    {
      Scaleform::Render::ComputeBoundsRoundStroke<Scaleform::Render::Matrix2x4<float>>(
        &result,
        shape,
        trans,
        &pos,
        coord,
        styles);
      x2 = result.x2;
      x1 = result.x1;
      if ( result.x2 >= result.x1 )
      {
        y2 = result.y2;
        y1 = result.y1;
        if ( result.y2 >= result.y1 )
        {
          v11 = bounds->x1;
          if ( bounds->x1 >= result.x1 )
            v11 = result.x1;
          v12 = bounds->y1;
          bounds->x1 = v11;
          if ( v12 >= y1 )
            v12 = y1;
          v13 = bounds->x2;
          bounds->y1 = v12;
          if ( x1 >= v13 )
            v13 = x1;
          v14 = bounds->y2;
          bounds->x2 = v13;
          if ( y1 >= v14 )
            v14 = y1;
          bounds->y2 = v14;
          if ( v11 >= x2 )
            v11 = x2;
          bounds->x1 = v11;
          if ( v12 >= y2 )
            v12 = y2;
          bounds->y1 = v12;
          if ( x2 >= v13 )
            v13 = x2;
          bounds->x2 = v13;
          if ( y2 >= v14 )
            v14 = y2;
          bounds->y2 = v14;
        }
      }
    }
    else
    {
      shape->vfptr[10].__vecDelDtor(shape, (unsigned int)&pos);
    }
  }
}

// File Line: 310
// RVA: 0x92A090
Scaleform::Render::Rect<float> *__fastcall Scaleform::Render::ComputeBoundsFillAndStrokesSimplified<Scaleform::Render::Matrix2x4<float>>(
        Scaleform::Render::Rect<float> *result,
        Scaleform::Render::ShapeDataInterface *shape,
        Scaleform::Render::Matrix2x4<float> *trans,
        Scaleform::Render::BoundEdges edgesToCheck)
{
  result->x1 = 1.0e30;
  result->y1 = 1.0e30;
  result->x2 = -1.0e30;
  result->y2 = -1.0e30;
  Scaleform::Render::ExpandBoundsToFill<Scaleform::Render::Matrix2x4<float>>(shape, trans, result, edgesToCheck);
  if ( ((unsigned int (__fastcall *)(Scaleform::Render::ShapeDataInterface *))shape->vfptr[3].__vecDelDtor)(shape) )
  {
    ((void (__fastcall *)(Scaleform::Render::ShapeDataInterface *))shape->vfptr[7].__vecDelDtor)(shape);
    Scaleform::Render::ExpandBoundsToStrokesSimplified<Scaleform::Render::Matrix2x4<float>>(shape, trans, result);
  }
  return result;
}

// File Line: 335
// RVA: 0x92A2D0
Scaleform::Render::Rect<float> *__fastcall Scaleform::Render::ComputeBoundsRoundStrokeSorter<Scaleform::Render::Matrix2x4<float>>(
        Scaleform::Render::Rect<float> *result,
        Scaleform::Render::ShapeDataInterface *shape,
        Scaleform::Render::ShapePosInfo *pos,
        unsigned int strokeStyleIdx,
        Scaleform::Render::Matrix2x4<float> *trans,
        float scaledWidth,
        Scaleform::Render::StrokeGenerator *gen)
{
  Scaleform::Render::Matrix2x4<float> *v8; // r9
  Scaleform::Render::StrokeGenerator *v10; // rsi
  unsigned int v11; // eax
  __int64 Pages; // rdx
  float v13; // xmm10_4
  float v14; // xmm11_4
  float v15; // xmm8_4
  unsigned __int64 v16; // rcx
  __int64 v17; // r15
  float v18; // xmm7_4
  unsigned int v19; // edi
  Scaleform::Render::StrokeSorter::VertexType **v20; // r13
  Scaleform::Render::StrokeSorter::PathType *v21; // r12
  unsigned int v22; // ecx
  unsigned int v23; // eax
  __int64 v24; // rsi
  unsigned __int8 v25; // al
  unsigned int v26; // ecx
  unsigned int v27; // eax
  float v28; // xmm9_4
  float *p_x; // rdx
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
  float y2; // xmm0_4
  unsigned int v54; // ecx
  unsigned int v55; // eax
  unsigned int v56; // edi
  unsigned __int64 v57; // rax
  unsigned int v58; // ecx
  float *v59; // rbp
  unsigned int v60; // eax
  float v61; // xmm13_4
  float v62; // xmm14_4
  float *v63; // r14
  float v64; // xmm10_4
  float v65; // xmm9_4
  float v66; // xmm3_4
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
  float v78; // xmm3_4
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
  float x1; // xmm0_4
  float y1; // xmm1_4
  float x2; // xmm0_4
  float v119; // xmm2_4
  Scaleform::Render::Rect<float> *v120; // rax
  float v121; // xmm4_4
  float v122; // xmm3_4
  float v123; // xmm3_4
  float v124; // xmm2_4
  float v125; // xmm4_4
  float t2; // [rsp+30h] [rbp-E8h] BYREF
  unsigned int v127; // [rsp+34h] [rbp-E4h]
  unsigned int v128; // [rsp+38h] [rbp-E0h]
  __int64 v129; // [rsp+40h] [rbp-D8h]
  float t1; // [rsp+120h] [rbp+8h] BYREF

  v8 = trans;
  result->x1 = 1.0e30;
  result->y1 = 1.0e30;
  result->x2 = -1.0e30;
  result->y2 = -1.0e30;
  v10 = gen;
  Scaleform::Render::AddStrokeToSorter<Scaleform::Render::Matrix2x4<float>>(shape, pos, strokeStyleIdx, v8);
  v11 = 0;
  v127 = 0;
  if ( !LODWORD(v10->mStrokeSorter.OutPaths.Size) )
    goto LABEL_114;
  Pages = (__int64)v10->mStrokeSorter.OutPaths.Pages;
  v129 = Pages;
  v13 = FLOAT_2_0;
  v14 = *(float *)&FLOAT_1_0;
  do
  {
    v15 = 0.0;
    v16 = (unsigned __int64)v11 >> 4;
    v17 = v11 & 0xF;
    v18 = 0.0;
    v19 = 0;
    v128 = *(_DWORD *)(*(_QWORD *)(Pages + 8 * v16) + 8 * v17 + 4) & 0xFFFFFFF;
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
      v24 = (__int64)&v20[(unsigned __int64)(v22 + v21[v17].start) >> 4][((_BYTE)v22 + LOBYTE(v21[v17].start)) & 0xF];
      v25 = *(_BYTE *)(v24 + 12);
      if ( v25 < 2u )
      {
        v15 = *(float *)v24;
        x1 = result->x1;
        v18 = *(float *)(v24 + 4);
        if ( result->x1 >= *(float *)v24 )
          x1 = *(float *)v24;
        y1 = result->y1;
        result->x1 = x1;
        if ( y1 >= v18 )
          y1 = v18;
        x2 = result->x2;
        result->y1 = y1;
        if ( v15 >= x2 )
          x2 = v15;
        result->x2 = x2;
        y2 = result->y2;
        if ( v18 >= y2 )
          y2 = v18;
      }
      else if ( v25 == 2 )
      {
        v26 = v19;
        v27 = v21[v17].numVer & 0xFFFFFFF;
        if ( v19 >= v27 )
          v26 = v19 - v27;
        v28 = *(float *)v24;
        ++v19;
        p_x = &v20[(unsigned __int64)(v21[v17].start + v26) >> 4][(LOBYTE(v21[v17].start) + (_BYTE)v26) & 0xF].x;
        v30 = *p_x;
        v31 = (float)((float)(*(float *)v24 * v13) - v15) - *p_x;
        if ( v31 != 0.0 )
        {
          v32 = (float)(v28 - v15) / v31;
          if ( v32 > 0.0 && v32 < v14 )
          {
            v33 = (float)((float)(*(float *)(v24 + 4) - v18) * v32) + v18;
            v34 = (float)((float)((float)((float)((float)(p_x[1] - *(float *)(v24 + 4)) * v32) + *(float *)(v24 + 4))
                                - v33)
                        * v32)
                + v33;
            v35 = result->x1;
            v36 = (float)((float)((float)((float)((float)(v30 - v28) * v32) + v28)
                                - (float)((float)((float)(v28 - v15) * v32) + v15))
                        * v32)
                + (float)((float)((float)(v28 - v15) * v32) + v15);
            if ( result->x1 >= v36 )
              v35 = (float)((float)((float)((float)((float)(v30 - v28) * v32) + v28)
                                  - (float)((float)((float)(v28 - v15) * v32) + v15))
                          * v32)
                  + (float)((float)((float)(v28 - v15) * v32) + v15);
            result->x1 = v35;
            v37 = result->y1;
            if ( v37 >= v34 )
              v37 = v34;
            result->y1 = v37;
            v38 = result->x2;
            if ( v36 >= v38 )
              v38 = (float)((float)((float)((float)((float)(v30 - v28) * v32) + v28)
                                  - (float)((float)((float)(v28 - v15) * v32) + v15))
                          * v32)
                  + (float)((float)((float)(v28 - v15) * v32) + v15);
            result->x2 = v38;
            v39 = result->y2;
            if ( v34 >= v39 )
              v39 = v34;
            result->y2 = v39;
          }
        }
        v40 = *(float *)(v24 + 4);
        v41 = p_x[1];
        v42 = (float)((float)(v40 * v13) - v18) - v41;
        if ( v42 != 0.0 )
        {
          v43 = (float)(v40 - v18) / v42;
          if ( v43 > 0.0 && v43 < v14 )
          {
            v44 = (float)((float)((float)((float)((float)(v41 - v40) * v43) + v40)
                                - (float)((float)((float)(v40 - v18) * v43) + v18))
                        * v43)
                + (float)((float)((float)(v40 - v18) * v43) + v18);
            v45 = result->x1;
            v46 = (float)((float)((float)((float)((float)(v30 - v28) * v43) + v28)
                                - (float)((float)((float)(v28 - v15) * v43) + v15))
                        * v43)
                + (float)((float)((float)(v28 - v15) * v43) + v15);
            if ( result->x1 >= v46 )
              v45 = (float)((float)((float)((float)((float)(v30 - v28) * v43) + v28)
                                  - (float)((float)((float)(v28 - v15) * v43) + v15))
                          * v43)
                  + (float)((float)((float)(v28 - v15) * v43) + v15);
            result->x1 = v45;
            v47 = result->y1;
            if ( v47 >= v44 )
              v47 = v44;
            result->y1 = v47;
            v48 = result->x2;
            if ( v46 >= v48 )
              v48 = (float)((float)((float)((float)((float)(v30 - v28) * v43) + v28)
                                  - (float)((float)((float)(v28 - v15) * v43) + v15))
                          * v43)
                  + (float)((float)((float)(v28 - v15) * v43) + v15);
            result->x2 = v48;
            v49 = result->y2;
            if ( v44 >= v49 )
              v49 = v44;
            result->y2 = v49;
          }
        }
        v50 = result->x1;
        if ( result->x1 >= v30 )
          v50 = v30;
        v51 = result->y1;
        result->x1 = v50;
        if ( v51 >= v41 )
          v51 = v41;
        v52 = result->x2;
        result->y1 = v51;
        if ( v30 >= v52 )
          v52 = v30;
        result->x2 = v52;
        y2 = result->y2;
        if ( v41 >= y2 )
          y2 = v41;
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
          v72 = result->x1;
          v73 = (float)((float)((float)((float)((float)((float)((float)((float)(v64 - v61) * t1) + v61) - v67) * t1)
                                      + v67)
                              - v69)
                      * t1)
              + v69;
          if ( result->x1 >= v73 )
            v72 = (float)((float)((float)((float)((float)((float)((float)((float)(v64 - v61) * t1) + v61) - v67) * t1)
                                        + v67)
                                - v69)
                        * t1)
                + v69;
          result->x1 = v72;
          v74 = result->y1;
          if ( v74 >= v71 )
            v74 = v71;
          result->y1 = v74;
          v75 = result->x2;
          if ( v73 >= v75 )
            v75 = (float)((float)((float)((float)((float)((float)((float)((float)(v64 - v61) * v65) + v61) - v67) * v65)
                                        + v67)
                                - v69)
                        * v65)
                + v69;
          result->x2 = v75;
          v76 = result->y2;
          if ( v71 >= v76 )
            v76 = v71;
          result->y2 = v76;
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
          v84 = result->x1;
          v85 = (float)((float)((float)((float)((float)((float)((float)((float)(v64 - v61) * t2) + v61) - v79) * t2)
                                      + v79)
                              - v81)
                      * t2)
              + v81;
          if ( result->x1 >= v85 )
            v84 = (float)((float)((float)((float)((float)((float)((float)((float)(v64 - v61) * t2) + v61) - v79) * t2)
                                        + v79)
                                - v81)
                        * t2)
                + v81;
          result->x1 = v84;
          v86 = result->y1;
          if ( v86 >= v83 )
            v86 = v83;
          result->y1 = v86;
          v87 = result->x2;
          if ( v85 >= v87 )
            v87 = (float)((float)((float)((float)((float)((float)((float)((float)(v64 - v61) * v77) + v61) - v79) * v77)
                                        + v79)
                                - v81)
                        * v77)
                + v81;
          result->x2 = v87;
          v88 = result->y2;
          if ( v83 >= v88 )
            v88 = v83;
          result->y2 = v88;
        }
        v89 = v63[1];
        v90 = v59[1];
        v91 = *(float *)(v24 + 4);
        Scaleform::Render::Math2D::CubicCurveExtremum(v18, v91, v90, v89, &t1, &t2);
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
          v98 = result->x1;
          v99 = (float)((float)((float)((float)((float)((float)((float)((float)(v64 - v61) * t1) + v61) - v94) * t1)
                                      + v94)
                              - v95)
                      * t1)
              + v95;
          if ( result->x1 >= v99 )
            v98 = (float)((float)((float)((float)((float)((float)((float)((float)(v64 - v61) * t1) + v61) - v94) * t1)
                                        + v94)
                                - v95)
                        * t1)
                + v95;
          result->x1 = v98;
          v100 = result->y1;
          if ( v100 >= v97 )
            v100 = v97;
          result->y1 = v100;
          v101 = result->x2;
          if ( v99 >= v101 )
            v101 = (float)((float)((float)((float)((float)((float)((float)((float)(v64 - v61) * v92) + v61) - v94) * v92)
                                         + v94)
                                 - v95)
                         * v92)
                 + v95;
          result->x2 = v101;
          v102 = result->y2;
          if ( v97 >= v102 )
            v102 = v97;
          result->y2 = v102;
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
          v108 = result->x1;
          v109 = (float)((float)((float)((float)((float)((float)((float)((float)(v64 - v61) * t2) + v61) - v104) * t2)
                                       + v104)
                               - v105)
                       * t2)
               + v105;
          if ( result->x1 >= v109 )
            v108 = (float)((float)((float)((float)((float)((float)((float)((float)(v64 - v61) * t2) + v61) - v104) * t2)
                                         + v104)
                                 - v105)
                         * t2)
                 + v105;
          result->x1 = v108;
          v110 = result->y1;
          if ( v110 >= v107 )
            v110 = v107;
          result->y1 = v110;
          v111 = result->x2;
          if ( v109 >= v111 )
            v111 = (float)((float)((float)((float)((float)((float)((float)((float)(v64 - v61) * v103) + v61) - v104)
                                                 * v103)
                                         + v104)
                                 - v105)
                         * v103)
                 + v105;
          result->x2 = v111;
          v112 = result->y2;
          if ( v107 >= v112 )
            v112 = v107;
          result->y2 = v112;
        }
        v113 = result->x1;
        if ( result->x1 >= v64 )
          v113 = v64;
        v114 = result->y1;
        result->x1 = v113;
        if ( v114 >= v89 )
          v114 = v89;
        v115 = result->x2;
        result->y1 = v114;
        if ( v64 >= v115 )
          v115 = v64;
        result->x2 = v115;
        y2 = result->y2;
        if ( v89 >= y2 )
          y2 = v89;
        v14 = *(float *)&FLOAT_1_0;
        v15 = v64;
        v13 = FLOAT_2_0;
        v18 = v89;
      }
      result->y2 = y2;
    }
    while ( v19 < v128 );
    v10 = gen;
    Pages = v129;
LABEL_113:
    v11 = v127 + 1;
    v127 = v11;
  }
  while ( v11 < LODWORD(v10->mStrokeSorter.OutPaths.Size) );
LABEL_114:
  v119 = result->x2;
  v120 = result;
  if ( v119 >= result->x1 )
  {
    v121 = result->y2;
    v122 = result->y1;
    if ( v121 >= v122 )
    {
      v123 = v122 - (float)(scaledWidth * 0.5);
      v124 = v119 + (float)(scaledWidth * 0.5);
      v125 = v121 + (float)(scaledWidth * 0.5);
      result->x1 = result->x1 - (float)(scaledWidth * 0.5);
      result->y1 = v123;
      result->x2 = v124;
      result->y2 = v125;
    }
  }
  return v120;
}5);
      result->y1 = v123;
      result->x2 = v124;
      result->y2 = v125;
    }
  }
  return v120;
}

// File Line: 429
// RVA: 0x92AE10
Scaleform::Render::Rect<float> *__fastcall Scaleform::Render::ComputeBoundsSingleStroke<Scaleform::Render::Matrix2x4<float>>(
        Scaleform::Render::Rect<float> *result,
        Scaleform::Render::ShapeDataInterface *shape,
        Scaleform::Render::ShapePosInfo *pos,
        unsigned int strokeStyleIdx,
        Scaleform::Render::Matrix2x4<float> *trans,
        Scaleform::Render::StrokeGenerator *gen,
        Scaleform::Render::ToleranceParams *tol)
{
  Scaleform::Render::Rect<float> *v10; // r15
  float v11; // xmm1_4
  int v12; // ecx
  __m128 v13; // xmm1
  int v14; // ecx
  void (__fastcall ***v15)(_QWORD, __int64); // rcx
  Scaleform::Render::StrokerTypes::LineJoinType v16; // edx
  Scaleform::Render::StrokerTypes::LineCapType v17; // r10d
  Scaleform::Render::StrokerTypes::LineCapType v18; // r8d
  int v19; // eax
  unsigned int v20; // r12d
  float v21; // xmm6_4
  float v22; // xmm7_4
  float v23; // xmm8_4
  float v24; // xmm9_4
  Scaleform::Render::VertexPath *p_mPath; // rcx
  unsigned __int64 v26; // r15
  __int64 v27; // rdi
  unsigned int v28; // esi
  unsigned int v29; // ebx
  Scaleform::Render::StrokeSorter::PathType *v30; // rdx
  unsigned int v31; // eax
  unsigned int v32; // ecx
  Scaleform::Render::StrokeSorter::VertexType **Pages; // r10
  __int64 v34; // r8
  unsigned __int8 v35; // al
  unsigned int v36; // eax
  unsigned int v37; // ecx
  float *p_x; // rdx
  unsigned int v39; // eax
  unsigned int v40; // ecx
  float *v41; // r9
  unsigned int v42; // ebx
  unsigned int v43; // eax
  unsigned int v44; // ecx
  float *v45; // rdx
  unsigned int v46; // edx
  unsigned __int64 Size; // r8
  unsigned __int64 v48; // rcx
  unsigned __int64 v49; // rax
  __int64 v50; // rcx
  Scaleform::Render::VertexBasic *v51; // rax
  float y; // xmm0_4
  float x; // xmm1_4
  void (__fastcall ***v54)(_QWORD, __int64); // rcx
  void (__fastcall ***v55)(_QWORD, __int64); // rcx
  float v57; // [rsp+60h] [rbp-98h] BYREF
  int v58; // [rsp+68h] [rbp-90h]
  float v59; // [rsp+6Ch] [rbp-8Ch]
  __int64 v60; // [rsp+78h] [rbp-80h]
  __int64 v61; // [rsp+80h] [rbp-78h]

  v10 = result;
  v60 = 0i64;
  v61 = 0i64;
  ((void (__fastcall *)(Scaleform::Render::ShapeDataInterface *, _QWORD, float *))shape->vfptr[5].__vecDelDtor)(
    shape,
    strokeStyleIdx,
    &v57);
  v11 = *(float *)&FLOAT_1_0;
  v12 = v58 & 6;
  if ( (v58 & 6) == 0 )
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
    LODWORD(v11) = _mm_sqrt_ps(v13).m128_u32[0];
  }
  v14 = v58 & 0x30;
  if ( (v58 & 0x30) != 0 || (v58 & 0xC0) != 0 )
  {
    v16 = RoundJoin;
    v17 = RoundCap;
    v18 = RoundCap;
    if ( v14 == 16 )
    {
      v16 = BevelJoin;
    }
    else if ( v14 == 32 )
    {
      v16 = MiterJoin;
    }
    if ( (v58 & 0xC0) == 64 )
    {
      v17 = ButtCap;
    }
    else if ( (v58 & 0xC0) == 128 )
    {
      v17 = SquareCap;
    }
    v19 = v58 & 0x300;
    if ( v19 == 256 )
    {
      v18 = ButtCap;
    }
    else if ( v19 == 512 )
    {
      v18 = SquareCap;
    }
    gen->mStroker.Width = (float)(v57 * v11) * 0.5;
    gen->mStroker.LineJoin = v16;
    gen->mStroker.StartLineCap = v17;
    gen->mStroker.EndLineCap = v18;
    gen->mStroker.MiterLimit = v59;
    gen->mStroker.CurveTolerance = tol->CurveTolerance;
    gen->mStroker.IntersectionEpsilon = tol->IntersectionEpsilon;
    Scaleform::Render::AddStrokeToSorter<Scaleform::Render::Matrix2x4<float>>(shape, pos, strokeStyleIdx, trans);
    (*((void (__fastcall **)(Scaleform::Render::Stroker *))&gen->mStroker.vfptr->__vecDelDtor + 1))(&gen->mStroker);
    v20 = 0;
    v21 = *((float *)&_xmm_f149f2caf149f2ca7149f2ca7149f2ca + 3);
    v22 = *((float *)&_xmm_f149f2caf149f2ca7149f2ca7149f2ca + 2);
    v23 = *((float *)&_xmm_f149f2caf149f2ca7149f2ca7149f2ca + 1);
    v24 = *(float *)&_xmm_f149f2caf149f2ca7149f2ca7149f2ca;
    if ( LODWORD(gen->mStrokeSorter.OutPaths.Size) )
    {
      p_mPath = &gen->mPath;
      do
      {
        (*((void (__fastcall **)(Scaleform::Render::VertexPath *))&p_mPath->vfptr->__vecDelDtor + 1))(p_mPath);
        v26 = (unsigned __int64)v20 >> 4;
        v27 = v20 & 0xF;
        v28 = gen->mStrokeSorter.OutPaths.Pages[v26][v27].numVer & 0xFFFFFFF;
        v29 = 0;
        while ( v29 < v28 )
        {
          v30 = gen->mStrokeSorter.OutPaths.Pages[v26];
          v31 = v30[v27].numVer & 0xFFFFFFF;
          v32 = v29;
          if ( v29 >= v31 )
            v32 = v29 - v31;
          Pages = gen->mStrokeSorter.OutVertices.Pages;
          v34 = (__int64)&Pages[(unsigned __int64)(v32 + v30[v27].start) >> 4][((_BYTE)v32 + LOBYTE(v30[v27].start)) & 0xF];
          ++v29;
          v35 = *(_BYTE *)(v34 + 12);
          if ( v35 < 2u )
          {
            ((void (__fastcall *)(Scaleform::Render::Stroker *))gen->mStroker.vfptr->AddVertex)(&gen->mStroker);
          }
          else if ( v35 == 2 )
          {
            v36 = v30[v27].numVer & 0xFFFFFFF;
            v37 = v29;
            if ( v29 >= v36 )
              v37 = v29 - v36;
            p_x = &Pages[(unsigned __int64)(v30[v27].start + v37) >> 4][(LOBYTE(v30[v27].start) + (_BYTE)v37) & 0xF].x;
            ++v29;
            Scaleform::Render::TessellateQuadCurve(
              &gen->mStroker,
              tol,
              *(float *)v34,
              *(float *)(v34 + 4),
              *p_x,
              p_x[1]);
          }
          else if ( v35 == 3 )
          {
            v39 = v30[v27].numVer & 0xFFFFFFF;
            v40 = v29;
            if ( v29 >= v39 )
              v40 = v29 - v39;
            v41 = &Pages[(unsigned __int64)(v40 + v30[v27].start) >> 4][((_BYTE)v40 + LOBYTE(v30[v27].start)) & 0xF].x;
            v42 = v29 + 1;
            v43 = v30[v27].numVer & 0xFFFFFFF;
            v44 = v42;
            if ( v42 >= v43 )
              v44 = v42 - v43;
            v45 = &Pages[(unsigned __int64)(v30[v27].start + v44) >> 4][(LOBYTE(v30[v27].start) + (_BYTE)v44) & 0xF].x;
            v29 = v42 + 1;
            Scaleform::Render::TessellateCubicCurve(
              &gen->mStroker,
              tol,
              *(float *)v34,
              *(float *)(v34 + 4),
              *v41,
              v41[1],
              *v45,
              v45[1]);
          }
        }
        Scaleform::Render::Stroker::GenerateStroke(&gen->mStroker, &gen->mPath);
        v46 = 0;
        Size = gen->mPath.Vertices.Size;
        if ( Size )
        {
          v48 = 0i64;
          do
          {
            v49 = v48 >> 4;
            v50 = v48 & 0xF;
            v51 = gen->mPath.Vertices.Pages[v49];
            y = v51[v50].y;
            x = v51[v50].x;
            if ( v24 >= x )
              v24 = v51[v50].x;
            if ( v23 >= y )
              v23 = v51[v50].y;
            if ( x >= v22 )
              v22 = v51[v50].x;
            if ( y >= v21 )
              v21 = v51[v50].y;
            v48 = ++v46;
          }
          while ( v46 < Size );
        }
        ++v20;
        p_mPath = &gen->mPath;
      }
      while ( v20 < LODWORD(gen->mStrokeSorter.OutPaths.Size) );
      v10 = result;
    }
    v10->x1 = v24;
    v10->y1 = v23;
    v10->x2 = v22;
    v10->y2 = v21;
    v54 = (void (__fastcall ***)(_QWORD, __int64))v61;
    if ( v61 && !_InterlockedDecrement((volatile signed __int32 *)(v61 + 8)) && v54 )
      (**v54)(v54, 1i64);
  }
  else
  {
    Scaleform::Render::ComputeBoundsRoundStrokeSorter<Scaleform::Render::Matrix2x4<float>>(
      v10,
      shape,
      pos,
      strokeStyleIdx,
      trans,
      v57 * v11,
      gen);
    v15 = (void (__fastcall ***)(_QWORD, __int64))v61;
    if ( v61 && !_InterlockedDecrement((volatile signed __int32 *)(v61 + 8)) && v15 )
      (**v15)(v15, 1i64);
  }
  v55 = (void (__fastcall ***)(_QWORD, __int64))v60;
  if ( v60 && !_InterlockedDecrement((volatile signed __int32 *)(v60 + 8)) && v55 )
    (**v55)(v55, 1i64);
  return v10;
}

// File Line: 532
// RVA: 0x92B720
void __fastcall Scaleform::Render::ExpandBoundsToLayerStrokes<Scaleform::Render::Matrix2x4<float>>(
        Scaleform::Render::ShapeDataInterface *shape,
        Scaleform::Render::ShapePosInfo *pos,
        Scaleform::Render::Matrix2x4<float> *trans,
        Scaleform::Render::StrokeGenerator *gen)
{
  Scaleform::Render::StrokeGenerator *v4; // r14
  Scaleform::MemoryHeap *pHeap; // rax
  char v9; // bl
  int v10; // eax
  float *v11; // rdi
  Scaleform::Render::ToleranceParams *v12; // r13
  float v13; // xmm6_4
  float v14; // xmm0_4
  float v15; // xmm5_4
  float v16; // xmm4_4
  float v17; // xmm1_4
  float v18; // xmm2_4
  float v19; // xmm3_4
  float v20; // xmm0_4
  unsigned __int64 NumStrokeBits; // r14
  __int64 v22; // r15
  unsigned int v23; // ebx
  __int64 v24; // rax
  __int64 v25; // rax
  int v26; // [rsp+14h] [rbp-7Dh]
  __int64 v27; // [rsp+18h] [rbp-79h]
  Scaleform::Render::Matrix2x4<float> *transa; // [rsp+20h] [rbp-71h]
  Scaleform::Render::StrokeGenerator *gena; // [rsp+28h] [rbp-69h]
  Scaleform::Render::ToleranceParams *v30; // [rsp+30h] [rbp-61h]
  float Sfactor; // [rsp+38h] [rbp-59h]
  int v32; // [rsp+3Ch] [rbp-55h]
  Scaleform::Render::ShapePosInfo posa; // [rsp+40h] [rbp-51h] BYREF
  __int64 v34; // [rsp+78h] [rbp-19h]
  char v35[80]; // [rsp+80h] [rbp-11h] BYREF
  Scaleform::Render::Matrix2x4<float> *v36; // [rsp+F8h] [rbp+67h]
  Scaleform::Render::StrokeGenerator *v37; // [rsp+100h] [rbp+6Fh]
  Scaleform::Render::ToleranceParams *v38; // [rsp+108h] [rbp+77h]
  float *vars0; // [rsp+110h] [rbp+7Fh]

  v34 = -2i64;
  v4 = gen;
  pHeap = gen->Heap1.pHeap;
  *(_QWORD *)&posa.Pos = 32i64;
  *(_QWORD *)&posa.StartY = &posa.StartX;
  *(_QWORD *)&posa.LastY = pHeap;
  v9 = 1;
  posa.Pos = pos->Pos;
  posa.StartX = pos->StartX;
  posa.StartY = pos->StartY;
  transa = *(Scaleform::Render::Matrix2x4<float> **)&pos->StrokeBase;
  gena = *(Scaleform::Render::StrokeGenerator **)&pos->NumStrokeBits;
  v30 = *(Scaleform::Render::ToleranceParams **)&pos->Fill1;
  Sfactor = pos->Sfactor;
  v32 = *(_DWORD *)&pos->Initialized;
  v10 = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, Scaleform::Render::ShapePosInfo *, char *, unsigned int *))shape->vfptr[8].__vecDelDtor)(
          shape,
          pos,
          v35,
          &posa.StrokeBase);
  if ( v10 )
  {
    v11 = vars0;
    v12 = v38;
    do
    {
      if ( v10 == 2 && !v9 )
        break;
      if ( posa.NumStrokeBits
        && (posa.NumStrokeBits >= posa.Pos
         || (*(_DWORD *)(*(_QWORD *)&posa.StartY + 4 * ((unsigned __int64)posa.NumStrokeBits >> 5)) & (1 << (posa.NumStrokeBits & 0x1F))) == 0) )
      {
        Scaleform::Render::ComputeBoundsSingleStroke<Scaleform::Render::Matrix2x4<float>>(
          (Scaleform::Render::Rect<float> *)&posa.Fill1,
          shape,
          &posa,
          posa.NumStrokeBits,
          trans,
          v4,
          v12);
        v13 = posa.Sfactor;
        v14 = *(float *)&posa.Fill1;
        if ( posa.Sfactor >= *(float *)&posa.Fill1 )
        {
          v15 = *(float *)&posa.Initialized;
          v16 = *(float *)&posa.Stroke;
          if ( *(float *)&posa.Initialized >= *(float *)&posa.Stroke )
          {
            v17 = *v11;
            if ( *v11 >= *(float *)&posa.Fill1 )
              v17 = *(float *)&posa.Fill1;
            *v11 = v17;
            v18 = v11[1];
            if ( v18 >= v16 )
              v18 = v16;
            v11[1] = v18;
            v19 = v11[2];
            if ( v14 >= v19 )
              v19 = v14;
            v11[2] = v19;
            v20 = v11[3];
            if ( v16 >= v20 )
              v20 = v16;
            v11[3] = v20;
            if ( v17 >= v13 )
              v17 = v13;
            *v11 = v17;
            if ( v18 >= v15 )
              v18 = v15;
            v11[1] = v18;
            if ( v13 >= v19 )
              v19 = v13;
            v11[2] = v19;
            if ( v15 >= v20 )
              v20 = v15;
            v11[3] = v20;
          }
        }
        NumStrokeBits = posa.NumStrokeBits;
        if ( posa.NumStrokeBits >= posa.Pos )
        {
          v22 = (posa.Pos + 31) >> 5;
          v23 = (posa.NumStrokeBits + 32) >> 5;
          if ( v23 < 2 * (int)v22 )
            v23 = 2 * v22;
          if ( v23 > (unsigned int)v22 )
          {
            v24 = **(_QWORD **)&posa.LastY;
            if ( *(Scaleform::Render::ShapePosInfo **)&posa.StartY == (Scaleform::Render::ShapePosInfo *)&posa.StartX )
            {
              *(_QWORD *)&posa.StartY = (*(__int64 (__fastcall **)(_QWORD, __int64, _QWORD))(v24 + 80))(
                                          *(_QWORD *)&posa.LastY,
                                          4i64 * v23,
                                          0i64);
              **(_DWORD **)&posa.StartY = posa.StartX;
              v25 = *(_QWORD *)&posa.StartY;
            }
            else
            {
              v25 = (*(__int64 (__fastcall **)(_QWORD, _QWORD, __int64))(v24 + 88))(
                      *(_QWORD *)&posa.LastY,
                      *(_QWORD *)&posa.StartY,
                      4i64 * v23);
              *(_QWORD *)&posa.StartY = v25;
            }
            memset((void *)(v25 + 4 * v22), 0, 4i64 * (v23 - (unsigned int)v22));
            posa.Pos = 32 * v23;
          }
        }
        *(_DWORD *)(*(_QWORD *)&posa.StartY + 4 * (NumStrokeBits >> 5)) |= 1 << (NumStrokeBits & 0x1F);
        v4 = v37;
        trans = v36;
      }
      shape->vfptr[10].__vecDelDtor(shape, (unsigned int)pos);
      v9 = 0;
      posa.Pos = pos->Pos;
      posa.StartX = pos->StartX;
      posa.StartY = pos->StartY;
      transa = *(Scaleform::Render::Matrix2x4<float> **)&pos->StrokeBase;
      gena = *(Scaleform::Render::StrokeGenerator **)&pos->NumStrokeBits;
      v30 = *(Scaleform::Render::ToleranceParams **)&pos->Fill1;
      Sfactor = pos->Sfactor;
      v32 = *(_DWORD *)&pos->Initialized;
      v10 = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, Scaleform::Render::ShapePosInfo *, char *, unsigned int *))shape->vfptr[8].__vecDelDtor)(
              shape,
              pos,
              v35,
              &posa.StrokeBase);
    }
    while ( v10 );
  }
  pos->Pos = posa.Pos;
  pos->StartX = posa.StartX;
  pos->StartY = posa.StartY;
  pos->LastX = v26;
  *(_QWORD *)&pos->LastY = v27;
  *(_QWORD *)&pos->StrokeBase = transa;
  *(_QWORD *)&pos->NumStrokeBits = gena;
  *(_QWORD *)&pos->Fill1 = v30;
  pos->Sfactor = Sfactor;
  *(_DWORD *)&pos->Initialized = v32;
  if ( *(Scaleform::Render::ShapePosInfo **)&posa.StartY != (Scaleform::Render::ShapePosInfo *)&posa.StartX )
    (*(void (__fastcall **)(_QWORD))(**(_QWORD **)&posa.LastY + 96i64))(*(_QWORD *)&posa.LastY);
}

// File Line: 580
// RVA: 0x92BB50
void __fastcall Scaleform::Render::ExpandBoundsToStrokes<Scaleform::Render::Matrix2x4<float>>(
        Scaleform::Render::ShapeDataInterface *shape,
        Scaleform::Render::Matrix2x4<float> *trans,
        Scaleform::Render::StrokeGenerator *gen,
        Scaleform::Render::ToleranceParams *tol,
        Scaleform::Render::Rect<float> *bounds)
{
  __int64 v9; // r12
  __int64 v10; // r13
  Scaleform::Render::ShapePosInfo pos; // [rsp+30h] [rbp-51h] BYREF
  __int64 v12; // [rsp+68h] [rbp-19h]
  __int64 v13; // [rsp+70h] [rbp-11h]
  __int64 v14; // [rsp+78h] [rbp-9h]
  __int64 v15; // [rsp+80h] [rbp-1h]
  char v16[16]; // [rsp+88h] [rbp+7h] BYREF
  char v17[24]; // [rsp+98h] [rbp+17h] BYREF
  __int64 v18; // [rsp+E0h] [rbp+5Fh]

  pos.Pos = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *))shape->vfptr[6].__vecDelDtor)(shape);
  LODWORD(pos.Sfactor) = (_DWORD)FLOAT_1_0;
  memset(&pos.StartX, 0, 44);
  v9 = pos.Pos;
  v10 = 0i64;
  pos.Initialized = 0;
  v18 = 0i64;
  v13 = 0i64;
  v14 = 0i64;
  v15 = 0i64;
  v12 = *(_QWORD *)&pos.Sfactor;
  if ( ((unsigned int (__fastcall *)(Scaleform::Render::ShapeDataInterface *, Scaleform::Render::ShapePosInfo *, char *, char *))shape->vfptr[8].__vecDelDtor)(
         shape,
         &pos,
         v17,
         v16) )
  {
    do
    {
      *(_QWORD *)&pos.LastY = v18;
      *(_QWORD *)&pos.StrokeBase = v13;
      *(_QWORD *)&pos.NumStrokeBits = v14;
      *(_QWORD *)&pos.Fill1 = v15;
      *(_QWORD *)&pos.Pos = v9;
      *(_QWORD *)&pos.StartY = v10;
      *(_QWORD *)&pos.Sfactor = v12;
      Scaleform::Render::ExpandBoundsToLayerStrokes<Scaleform::Render::Matrix2x4<float>>(shape, &pos, trans, gen);
      v9 = *(_QWORD *)&pos.Pos;
      v10 = *(_QWORD *)&pos.StartY;
      v18 = *(_QWORD *)&pos.LastY;
      v13 = *(_QWORD *)&pos.StrokeBase;
      v14 = *(_QWORD *)&pos.NumStrokeBits;
      v15 = *(_QWORD *)&pos.Fill1;
      v12 = *(_QWORD *)&pos.Sfactor;
    }
    while ( ((unsigned int (__fastcall *)(Scaleform::Render::ShapeDataInterface *, Scaleform::Render::ShapePosInfo *, char *, char *, Scaleform::Render::ToleranceParams *, Scaleform::Render::Rect<float> *))shape->vfptr[8].__vecDelDtor)(
              shape,
              &pos,
              v17,
              v16,
              tol,
              bounds) );
  }
}

