#**************************************************************
#  
#  Licensed to the Apache Software Foundation (ASF) under one
#  or more contributor license agreements.  See the NOTICE file
#  distributed with this work for additional information
#  regarding copyright ownership.  The ASF licenses this file
#  to you under the Apache License, Version 2.0 (the
#  "License"); you may not use this file except in compliance
#  with the License.  You may obtain a copy of the License at
#  
#    http://www.apache.org/licenses/LICENSE-2.0
#  
#  Unless required by applicable law or agreed to in writing,
#  software distributed under the License is distributed on an
#  "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
#  KIND, either express or implied.  See the License for the
#  specific language governing permissions and limitations
#  under the License.
#  
#**************************************************************



# edit to match directory level 
PRJ		= ..$/..$/..
# same for all makefiles in "helpcontent2"
PRJNAME = helpcontent2
# edit to match the current package
PACKAGE = text/scalc
# uniqe name (module wide);
# using a modified form of package should do here
TARGET  = text_scalc
# edit to match the current module
MODULE  = scalc

# --- Settings -----------------------------------------------------
LANGUAGE_FILELIST="\
auxiliary/scalc.tree,\
text/scalc/00/00000004.xhp,\
text/scalc/00/00000402.xhp,\
text/scalc/00/00000403.xhp,\
text/scalc/00/00000404.xhp,\
text/scalc/00/00000405.xhp,\
text/scalc/00/00000406.xhp,\
text/scalc/00/00000407.xhp,\
text/scalc/00/00000412.xhp,\
text/scalc/01/01120000.xhp,\
text/scalc/01/02110000.xhp,\
text/scalc/01/02120000.xhp,\
text/scalc/01/02120100.xhp,\
text/scalc/01/02140000.xhp,\
text/scalc/01/02140100.xhp,\
text/scalc/01/02140200.xhp,\
text/scalc/01/02140300.xhp,\
text/scalc/01/02140400.xhp,\
text/scalc/01/02140500.xhp,\
text/scalc/01/02140600.xhp,\
text/scalc/01/02150000.xhp,\
text/scalc/01/02160000.xhp,\
text/scalc/01/02170000.xhp,\
text/scalc/01/02190000.xhp,\
text/scalc/01/02190100.xhp,\
text/scalc/01/02190200.xhp,\
text/scalc/01/02200000.xhp,\
text/scalc/01/02210000.xhp,\
text/scalc/01/03070000.xhp,\
text/scalc/01/03080000.xhp,\
text/scalc/01/03090000.xhp,\
text/scalc/01/03100000.xhp,\
text/scalc/01/04010000.xhp,\
text/scalc/01/04010100.xhp,\
text/scalc/01/04010200.xhp,\
text/scalc/01/04020000.xhp,\
text/scalc/01/04030000.xhp,\
text/scalc/01/04040000.xhp,\
text/scalc/01/04050000.xhp,\
text/scalc/01/04050100.xhp,\
text/scalc/01/04060000.xhp,\
text/scalc/01/04060100.xhp,\
text/scalc/01/04060101.xhp,\
text/scalc/01/04060102.xhp,\
text/scalc/01/04060103.xhp,\
text/scalc/01/04060104.xhp,\
text/scalc/01/04060105.xhp,\
text/scalc/01/04060106.xhp,\
text/scalc/01/04060107.xhp,\
text/scalc/01/04060108.xhp,\
text/scalc/01/04060109.xhp,\
text/scalc/01/04060110.xhp,\
text/scalc/01/04060111.xhp,\
text/scalc/01/04060112.xhp,\
text/scalc/01/04060115.xhp,\
text/scalc/01/04060116.xhp,\
text/scalc/01/04060118.xhp,\
text/scalc/01/04060119.xhp,\
text/scalc/01/04060181.xhp,\
text/scalc/01/04060182.xhp,\
text/scalc/01/04060183.xhp,\
text/scalc/01/04060184.xhp,\
text/scalc/01/04060185.xhp,\
text/scalc/01/04060199.xhp,\
text/scalc/01/04070000.xhp,\
text/scalc/01/04070100.xhp,\
text/scalc/01/04070200.xhp,\
text/scalc/01/04070300.xhp,\
text/scalc/01/04070400.xhp,\
text/scalc/01/04080000.xhp,\
text/scalc/01/04090000.xhp,\
text/scalc/01/05020000.xhp,\
text/scalc/01/05020600.xhp,\
text/scalc/01/05030000.xhp,\
text/scalc/01/05030200.xhp,\
text/scalc/01/05030300.xhp,\
text/scalc/01/05030400.xhp,\
text/scalc/01/05040000.xhp,\
text/scalc/01/05040200.xhp,\
text/scalc/01/05050000.xhp,\
text/scalc/01/05050100.xhp,\
text/scalc/01/05050300.xhp,\
text/scalc/01/05060000.xhp,\
text/scalc/01/05070000.xhp,\
text/scalc/01/05070500.xhp,\
text/scalc/01/05080000.xhp,\
text/scalc/01/05080100.xhp,\
text/scalc/01/05080200.xhp,\
text/scalc/01/05080300.xhp,\
text/scalc/01/05080400.xhp,\
text/scalc/01/05100000.xhp,\
text/scalc/01/05110000.xhp,\
text/scalc/01/05120000.xhp,\
text/scalc/01/06020000.xhp,\
text/scalc/01/06030000.xhp,\
text/scalc/01/06030100.xhp,\
text/scalc/01/06030200.xhp,\
text/scalc/01/06030300.xhp,\
text/scalc/01/06030400.xhp,\
text/scalc/01/06030500.xhp,\
text/scalc/01/06030600.xhp,\
text/scalc/01/06030700.xhp,\
text/scalc/01/06030800.xhp,\
text/scalc/01/06030900.xhp,\
text/scalc/01/06031000.xhp,\
text/scalc/01/06040000.xhp,\
text/scalc/01/06050000.xhp,\
text/scalc/01/06060000.xhp,\
text/scalc/01/06060100.xhp,\
text/scalc/01/06060200.xhp,\
text/scalc/01/06070000.xhp,\
text/scalc/01/06080000.xhp,\
text/scalc/01/06130000.xhp,\
text/scalc/01/06990000.xhp,\
text/scalc/01/07080000.xhp,\
text/scalc/01/07090000.xhp,\
text/scalc/01/12010000.xhp,\
text/scalc/01/12010100.xhp,\
text/scalc/01/12020000.xhp,\
text/scalc/01/12030000.xhp,\
text/scalc/01/12030100.xhp,\
text/scalc/01/12030200.xhp,\
text/scalc/01/12040000.xhp,\
text/scalc/01/12040100.xhp,\
text/scalc/01/12040201.xhp,\
text/scalc/01/12040300.xhp,\
text/scalc/01/12040400.xhp,\
text/scalc/01/12040500.xhp,\
text/scalc/01/12050000.xhp,\
text/scalc/01/12050100.xhp,\
text/scalc/01/12050200.xhp,\
text/scalc/01/12060000.xhp,\
text/scalc/01/12070000.xhp,\
text/scalc/01/12070100.xhp,\
text/scalc/01/12080000.xhp,\
text/scalc/01/12080100.xhp,\
text/scalc/01/12080200.xhp,\
text/scalc/01/12080300.xhp,\
text/scalc/01/12080400.xhp,\
text/scalc/01/12080500.xhp,\
text/scalc/01/12080600.xhp,\
text/scalc/01/12080700.xhp,\
text/scalc/01/12090000.xhp,\
text/scalc/01/12090100.xhp,\
text/scalc/01/12090101.xhp,\
text/scalc/01/12090102.xhp,\
text/scalc/01/12090103.xhp,\
text/scalc/01/12090104.xhp,\
text/scalc/01/12090105.xhp,\
text/scalc/01/12090106.xhp,\
text/scalc/01/12090200.xhp,\
text/scalc/01/12090300.xhp,\
text/scalc/01/12090400.xhp,\
text/scalc/01/12090105.xhp,\
text/scalc/01/12090106.xhp,\
text/scalc/01/12090200.xhp,\
text/scalc/01/12090300.xhp,\
text/scalc/01/12090400.xhp,\
text/scalc/01/12100000.xhp,\
text/scalc/01/12120000.xhp,\
text/scalc/01/12120100.xhp,\
text/scalc/01/12120200.xhp,\
text/scalc/01/12120300.xhp,\
text/scalc/01/format_graphic.xhp,\
text/scalc/01/func_datevalue.xhp,\
text/scalc/01/func_date.xhp,\
text/scalc/01/func_days360.xhp,\
text/scalc/01/func_days.xhp,\
text/scalc/01/func_day.xhp,\
text/scalc/01/func_eastersunday.xhp,\
text/scalc/01/func_edate.xhp,\
text/scalc/01/func_eomonth.xhp,\
text/scalc/01/func_hour.xhp,\
text/scalc/01/func_minute.xhp,\
text/scalc/01/func_month.xhp,\
text/scalc/01/func_networkdays.xhp,\
text/scalc/01/func_now.xhp,\
text/scalc/01/func_second.xhp,\
text/scalc/01/func_timevalue.xhp,\
text/scalc/01/func_time.xhp,\
text/scalc/01/func_today.xhp,\
text/scalc/01/func_weekday.xhp,\
text/scalc/01/func_weeknumadd.xhp,\
text/scalc/01/func_weeknum.xhp,\
text/scalc/01/func_workday.xhp,\
text/scalc/01/func_yearfrac.xhp,\
text/scalc/01/func_year.xhp,\
text/scalc/01/solver_options.xhp,\
text/scalc/01/solver.xhp,\
text/scalc/01/text2columns.xhp,\
text/scalc/02/02130000.xhp,\
text/scalc/02/02140000.xhp,\
text/scalc/02/02150000.xhp,\
text/scalc/02/02160000.xhp,\
text/scalc/02/02170000.xhp,\
text/scalc/02/06010000.xhp,\
text/scalc/02/06030000.xhp,\
text/scalc/02/06040000.xhp,\
text/scalc/02/06050000.xhp,\
text/scalc/02/06060000.xhp,\
text/scalc/02/06070000.xhp,\
text/scalc/02/06080000.xhp,\
text/scalc/02/08010000.xhp,\
text/scalc/02/08080000.xhp,\
text/scalc/02/10050000.xhp,\
text/scalc/02/10060000.xhp,\
text/scalc/02/18010000.xhp,\
text/scalc/02/18020000.xhp,\
text/scalc/04/01020000.xhp,\
text/scalc/05/02140000.xhp,\
text/scalc/05/empty_cells.xhp,\
text/scalc/guide/address_auto.xhp,\
text/scalc/guide/autofilter.xhp,\
text/scalc/guide/autoformat.xhp,\
text/scalc/guide/auto_off.xhp,\
text/scalc/guide/background.xhp,\
text/scalc/guide/borders.xhp,\
text/scalc/guide/calc_date.xhp,\
text/scalc/guide/calc_series.xhp,\
text/scalc/guide/calc_timevalues.xhp,\
text/scalc/guide/calculate.xhp,\
text/scalc/guide/cellcopy.xhp,\
text/scalc/guide/cell_enter.xhp,\
text/scalc/guide/cell_protect.xhp,\
text/scalc/guide/cellreference_dragdrop.xhp,\
text/scalc/guide/cellreferences_url.xhp,\
text/scalc/guide/cellreferences.xhp,\
text/scalc/guide/cellstyle_by_formula.xhp,\
text/scalc/guide/cellstyle_conditional.xhp,\
text/scalc/guide/cellstyle_minusvalue.xhp,\
text/scalc/guide/cell_unprotect.xhp,\
text/scalc/guide/consolidate.xhp,\
text/scalc/guide/csv_files.xhp,\
text/scalc/guide/csv_formula.xhp,\
text/scalc/guide/currency_format.xhp,\
text/scalc/guide/database_define.xhp,\
text/scalc/guide/database_filter.xhp,\
text/scalc/guide/database_sort.xhp,\
text/scalc/guide/datapilot_createtable.xhp,\
text/scalc/guide/datapilot_deletetable.xhp,\
text/scalc/guide/datapilot_edittable.xhp,\
text/scalc/guide/datapilot_filtertable.xhp,\
text/scalc/guide/datapilot_grouping.xhp,\
text/scalc/guide/datapilot_tipps.xhp,\
text/scalc/guide/datapilot_updatetable.xhp,\
text/scalc/guide/datapilot.xhp,\
text/scalc/guide/dbase_files.xhp,\
text/scalc/guide/design.xhp,\
text/scalc/guide/edit_multitables.xhp,\
text/scalc/guide/filters.xhp,\
text/scalc/guide/finding.xhp,\
text/scalc/guide/format_table.xhp,\
text/scalc/guide/format_value_userdef.xhp,\
text/scalc/guide/format_value.xhp,\
text/scalc/guide/formula_copy.xhp,\
text/scalc/guide/formula_enter.xhp,\
text/scalc/guide/formulas.xhp,\
text/scalc/guide/formula_value.xhp,\
text/scalc/guide/fraction_enter.xhp,\
text/scalc/guide/goalseek.xhp,\
text/scalc/guide/html_doc.xhp,\
text/scalc/guide/integer_leading_zero.xhp,\
text/scalc/guide/keyboard.xhp,\
text/scalc/guide/line_fix.xhp,\
text/scalc/guide/main.xhp,\
text/scalc/guide/mark_cells.xhp,\
text/scalc/guide/matrixformula.xhp,\
text/scalc/guide/move_dragdrop.xhp,\
text/scalc/guide/multioperation.xhp,\
text/scalc/guide/multi_tables.xhp,\
text/scalc/guide/multitables.xhp,\
text/scalc/guide/note_insert.xhp,\
text/scalc/guide/numbers_text.xhp,\
text/scalc/guide/print_details.xhp,\
text/scalc/guide/print_exact.xhp,\
text/scalc/guide/print_landscape.xhp,\
text/scalc/guide/printranges.xhp,\
text/scalc/guide/print_title_row.xhp,\
text/scalc/guide/relativ_absolut_ref.xhp,\
text/scalc/guide/rename_table.xhp,\
text/scalc/guide/rounding_numbers.xhp,\
text/scalc/guide/row_height.xhp,\
text/scalc/guide/scenario.xhp,\
text/scalc/guide/sorted_list.xhp,\
text/scalc/guide/specialfilter.xhp,\
text/scalc/guide/super_subscript.xhp,\
text/scalc/guide/table_cellmerge.xhp,\
text/scalc/guide/table_rotate.xhp,\
text/scalc/guide/table_view.xhp,\
text/scalc/guide/text_numbers.xhp,\
text/scalc/guide/text_rotate.xhp,\
text/scalc/guide/text_wrap.xhp,\
text/scalc/guide/userdefined_function.xhp,\
text/scalc/guide/validity.xhp,\
text/scalc/guide/value_with_name.xhp,\
text/scalc/guide/webquery.xhp,\
text/scalc/guide/year2000.xhp,\
text/scalc/main0000.xhp,\
text/scalc/main0100.xhp,\
text/scalc/main0101.xhp,\
text/scalc/main0102.xhp,\
text/scalc/main0103.xhp,\
text/scalc/main0104.xhp,\
text/scalc/main0105.xhp,\
text/scalc/main0106.xhp,\
text/scalc/main0107.xhp,\
text/scalc/main0112.xhp,\
text/scalc/main0200.xhp,\
text/scalc/main0202.xhp,\
text/scalc/main0203.xhp,\
text/scalc/main0205.xhp,\
text/scalc/main0206.xhp,\
text/scalc/main0208.xhp,\
text/scalc/main0210.xhp,\
text/scalc/main0214.xhp,\
text/scalc/main0218.xhp,\
text/scalc/main0503.xhp"

.IF "$(MAKETARGETS)"!="genPO"
.INCLUDE : settings.mk
.INCLUDE : $(PRJ)$/settings.pmk

# this list matches the *.xhp files to process
XHPFILES = \
   main0000.xhp \
   main0100.xhp \
   main0101.xhp \
   main0102.xhp \
   main0103.xhp \
   main0104.xhp \
   main0105.xhp \
   main0106.xhp \
   main0107.xhp \
   main0112.xhp \
   main0200.xhp \
   main0202.xhp \
   main0203.xhp \
   main0205.xhp \
   main0206.xhp \
   main0208.xhp \
   main0210.xhp \
   main0214.xhp \
   main0218.xhp \
   main0503.xhp 
	
# --- Targets ------------------------------------------------------

.INCLUDE :  target.mk
.INCLUDE : tg_help.mk
.ELSE
.INCLUDE :  target.mk
.ENDIF
