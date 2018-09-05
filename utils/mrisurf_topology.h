#pragma once
/*
 * @file utilities common to mrisurf*.c but not used outside them
 *
 */
/*
 * surfaces Author: Bruce Fischl, extracted from mrisurf.c by Bevin Brett
 *
 * $ © copyright-2014,2018 The General Hospital Corporation (Boston, MA) "MGH"
 *
 * Terms and conditions for use, reproduction, distribution and contribution
 * are found in the 'FreeSurfer Software License Agreement' contained
 * in the file 'LICENSE' found in the FreeSurfer distribution, and here:
 *
 * https://surfer.nmr.mgh.harvard.edu/fswiki/FreeSurferSoftwareLicense
 *
 * Reporting: freesurfer@nmr.mgh.harvard.edu
 *
 */
// Configurable support for checking that some of the parallel loops get the same
// results regardless of thread count
//
// Two common causes of this being false are
//          floating point reductions
//          random numbers being generated by parallel code 
//

#include "mrisurf_base.h"

int mrisSetVertexFaceIndex(MRI_SURFACE *mris, int vno, int fno);


int edgeExists(MRI_SURFACE *mris, int vno1, int vno2);
int triangleMarked(MRI_SURFACE *mris, int fno);
int mrisCountValidLinks(MRI_SURFACE *mris, int vno1, int vno2);
int isFace(MRI_SURFACE *mris, int vno0, int vno1, int vno2);
int findFace(MRI_SURFACE *mris, int vno0, int vno1, int vno2);
int mrisValidFaces(MRI_SURFACE *mris);
int vertexInFace(MRI_SURFACE *mris, int vno, int fno);
int findOtherEdgeFace(MRIS const *mris, int fno, int vno, int vn1);
int mrisRemoveLink(MRI_SURFACE *mris, int vno1, int vno2);
int findNonMarkedFace(MRIS *mris, int vno, int vn1);

int computeOrientation(MRIS *mris, int f, int v0, int v1);

static int vertexNeighbor(MRI_SURFACE *mris, int vno1, int vno2)
{
  int n;

  VERTEX_TOPOLOGY const * const v = &mris->vertices_topology[vno1];
  for (n = 0; n < v->vnum; n++)
    if (v->v[n] == vno2) {
      return (1);
    }
  return (0);
}

int mrisMarkBadEdgeVertices(MRI_SURFACE *mris, int mark);

#define MAX_VLIST 255
int mrisAddEdge(MRI_SURFACE *mris, int vno1, int vno2);
int mrisAddFace(MRI_SURFACE *mris, int vno0, int vno1, int vno2);

