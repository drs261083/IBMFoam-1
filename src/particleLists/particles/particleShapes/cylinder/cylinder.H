/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright (C) 2011-2015 OpenFOAM Foundation
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

Class
    Foam::particle

Description
    abstract class for a spherical particle

SourceFiles
    particle.C

\*---------------------------------------------------------------------------*/

#ifndef cylinder_H
#define cylinder_H

#include "particleShape.H"


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{
namespace IBM
{
namespace particleShapes
{

class cylinder
:
    public particleShape
{
    // Private member functions

        //- Particle diameter
        scalar d_;

        //- Point1
        vector p1_;

        //- Point2
        vector p2_;

        //- Mid point in axis
        vector centerPoint_;

        //- Cylinder axis
        vectorList axis_;

        virtual void calcSf();


public:

    //- Runtime type information
    TypeName("cylinder");

    // Constructor

        // Construct particle from dictionary entry
        cylinder
        (
            const fvMesh& mesh,
            const dictionary& dict
        );

    //- Destructor
    virtual ~cylinder();


    // Member functions

        //- Update cells inside particle and shells
        virtual void updateCellLists();

        //- Discretize particle on the surface and return the list of points.
        //  The created mesh will store values at the verticies rather than the
        //  cell centers.
        virtual void discretize();

        //- Particle diameter
        virtual scalar D() const;

        //- Frontal area
        virtual scalar A() const;

        //- Center of mass
        virtual const vector& CoM() const;

        //- Center of mass
        virtual vector& CoM();
};

}   // End particleShapes namespace
}   // End IBM namespace
}   // End Foam namespace

#endif