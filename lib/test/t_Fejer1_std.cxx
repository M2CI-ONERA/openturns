//                                               -*- C++ -*-
/**
 *  @brief The test file of class GaussKronrod
 *
 *  Copyright 2005-2019 Airbus-EDF-IMACS-Phimeca
 *
 *  This library is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with this library.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#include "openturns/OT.hxx"
#include "openturns/OTtestcode.hxx"
#include <cmath>

using namespace OT;
using namespace OT::Test;

typedef Collection<Complex> ComplexCollection;

int main(int, char *[])
{
  TESTPREAMBLE;
  OStream fullprint(std::cout);
  setRandomGenerator();

  try
  {
    SymbolicFunction f("x", "sin(x)");
    Scalar a = -2.5;
    Scalar b = 4.5;
    // Default parameters
    Fejer1 algo;
    // High-level interface
    algo = Fejer1(Indices(1, 20));
    Scalar value = algo.integrate(f, Interval(a, b))[0];
    Scalar ref = cos(a) - cos(b);
    const Scalar error = std::abs(value-ref);
    const Scalar reference_error = 1e-10;
    if (error<reference_error)
    {
    fullprint << "OK" << std::endl;
    }
    else 
    {
    fullprint << "NOT OK" << std::endl;
    }
    
  }
  catch (TestFailed & ex)
  {
    std::cerr << ex << std::endl;
    return ExitCode::Error;
  }


  return ExitCode::Success;
}
