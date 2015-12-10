#include <stdlib.h>
#include "../utilities.h"
#include "../structs.h"

/**
 * Breeds one offspring by randomly picking lectures from the first or second parent and putting them into the
 * offspring.
 *
 * Example: The parents below could result in ...
 * <table>
 *  <tr>
 *    <td style="width: 25px; height: 25px; border: solid 1px black; background-color: rgb(180, 180, 180);"></td>
 *    <td style="width: 25px; height: 25px; border: solid 1px black; background-color: rgb(180, 180, 180);"></td>
 *    <td style="width: 25px; height: 25px; border: solid 1px black; background-color: rgb(180, 180, 180);"></td>
 *    <td style="width: 25px; height: 25px; border: solid 1px black; background-color: rgb(180, 180, 180);"></td>
 *    <td style="width: 25px; height: 25px; border: solid 1px black; background-color: rgb(180, 180, 180);"></td>
 *    <td style="width: 25px; height: 25px; border: solid 1px white; border-right: solid 1px black;
 *    background-color: white;"></td>
 *    <td style="width: 25px; height: 25px; border: solid 1px black; background-color: white;"></td>
 *    <td style="width: 25px; height: 25px; border: solid 1px black; background-color: white;"></td>
 *    <td style="width: 25px; height: 25px; border: solid 1px black; background-color: white;"></td>
 *    <td style="width: 25px; height: 25px; border: solid 1px black; background-color: white;"></td>
 *    <td style="width: 25px; height: 25px; border: solid 1px black; background-color: white;"></td>
 *  </tr>
 * </table>
 * ... the offspring below.
 * <table>
 *  <tr>
 *    <td style="width: 25px; height: 25px; border: solid 1px black; background-color: rgb(180, 180, 180);"></td>
 *    <td style="width: 25px; height: 25px; border: solid 1px black; background-color: white;"></td>
 *    <td style="width: 25px; height: 25px; border: solid 1px black; background-color: white;"></td>
 *    <td style="width: 25px; height: 25px; border: solid 1px black; background-color: rgb(180, 180, 180);"></td>
 *    <td style="width: 25px; height: 25px; border: solid 1px black; background-color: white;"></td>
 *  </tr>
 * </table>
 *
 * @param[out] population gets new offspring added.
 * @param[in] currentPopulationSize size of the population in number of popmembers
 */
int crossoverMix(PopMember population[], int currentPopulationSize);

/**
 * Breeds two offsprings by picking a random crossover point for the parents and swapping the right sides with
 * eachother.
 *
 * Example: The parents below with the marked crossover point results in ...
 * <div style="font-size: 24px; float: left; margin-left: 115px;">&darr;</div>
 * <div style="font-size: 24px; margin-left: 355px;">&darr;</div>
 * <table>
 *  <tr>
 *    <td style="width: 25px; height: 25px; border: solid 1px black; background-color: rgb(180, 180, 180);"></td>
 *    <td style="width: 25px; height: 25px; border: solid 1px black; background-color: rgb(180, 180, 180);"></td>
 *    <td style="width: 25px; height: 25px; border: solid 1px black; background-color: rgb(180, 180, 180);"></td>
 *    <td style="width: 25px; height: 25px; border: solid 1px black; background-color: rgb(180, 180, 180);"></td>
 *    <td style="width: 25px; height: 25px; border: solid 1px black; background-color: rgb(180, 180, 180);"></td>
 *    <td style="width: 25px; height: 25px; border: solid 1px white; border-right: solid 1px black;
 *    background-color: white;"></td>
 *    <td style="width: 25px; height: 25px; border: solid 1px black; background-color: white;"></td>
 *    <td style="width: 25px; height: 25px; border: solid 1px black; background-color: white;"></td>
 *    <td style="width: 25px; height: 25px; border: solid 1px black; background-color: white;"></td>
 *    <td style="width: 25px; height: 25px; border: solid 1px black; background-color: white;"></td>
 *    <td style="width: 25px; height: 25px; border: solid 1px black; background-color: white;"></td>
 *  </tr>
 * </table>
 * ... the offsprings below.
 * <div style="font-size: 24px; float: left; margin-left: 115px;">&darr;</div>
 * <div style="font-size: 24px; margin-left: 355px;">&darr;</div>
 * <table>
 *  <tr>
 *    <td style="width: 25px; height: 25px; border: solid 1px black; background-color: rgb(180, 180, 180);"></td>
 *    <td style="width: 25px; height: 25px; border: solid 1px black; background-color: rgb(180, 180, 180);"></td>
 *    <td style="width: 25px; height: 25px; border: solid 1px black; background-color: rgb(180, 180, 180);"></td>
 *    <td style="width: 25px; height: 25px; border: solid 1px black; background-color: white;"></td>
 *    <td style="width: 25px; height: 25px; border: solid 1px black; background-color: white;"></td>
 *    <td style="width: 25px; height: 25px; border: solid 1px white; border-right: solid 1px black;
 *    background-color: white;"></td>
 *    <td style="width: 25px; height: 25px; border: solid 1px black; background-color: white;"></td>
 *    <td style="width: 25px; height: 25px; border: solid 1px black; background-color: white;"></td>
 *    <td style="width: 25px; height: 25px; border: solid 1px black; background-color: white;"></td>
 *    <td style="width: 25px; height: 25px; border: solid 1px black; background-color: rgb(180, 180, 180);"></td>
 *    <td style="width: 25px; height: 25px; border: solid 1px black; background-color: rgb(180, 180, 180);"></td>
 *  </tr>
 * </table>
 *
 * @param[out] population is an output array of PopMember's
 * @param[in] currentPopulationSize
 */
int crossoverSlice(PopMember population[], int currentPopulationSize);

int crossoverSwitch(PopMember population[], int currentPopulationSize);
