#include <stdlib.h>
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
 * @param[in] parent1 the first parent used for breeding
 * @param[in] parent2 the second parent used for breeding
 * @param[out] offspring the offspring that is generated through breeding
 */
void crossoverMix(PopMember parent1, PopMember parent2, PopMember offspring);

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
 * @param[in] parent1 the first parent used for breeding
 * @param[in] parent2 the second parent used for breeding
 * @param[out] offspring1 the first offspring that is generated through breeding
 * @param[out] offspring2 the second offspring that is generated through breeding
 */
void crossoverSlice(PopMember parent1, PopMember parent2, PopMember offspring1, PopMember offspring2);
