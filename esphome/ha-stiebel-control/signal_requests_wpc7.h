/*
 * Signal Request Table for WPL13E Heat Pump
 *
 * This file contains the device-specific signal request configuration.
 * To support a different heat pump model, create a new file like this
 * with the appropriate signals for that model.
 *
 * Usage: Include this file in your device-specific YAML (e.g., wpl13e.yaml)
 */

#ifndef SIGNAL_REQUESTS_WPL13E_H
#define SIGNAL_REQUESTS_WPL13E_H

#include "config.h"
#include "ha-stiebel-control.h"


// Configurable signal request table for WPL13E model
// Edit this table to customize which signals are requested and how often
static const SignalRequest signalRequests[] = {
    // ========================================================================
    // TIME AND DATE SIGNALS
    // ========================================================================
    {"JAHR", FREQ_10MIN, cm_manager}, // Works
    {"MONAT", FREQ_10MIN, cm_manager}, // Works
    {"TAG", FREQ_10MIN, cm_manager}, // Works
    {"STUNDE", FREQ_1MIN, cm_manager}, // Works
    {"MINUTE", FREQ_1MIN, cm_manager}, // Works
    {"SEKUNDE", FREQ_30S, cm_manager}, // Works

    // ========================================================================
    // STATUS AND CONTROL SIGNALS
    // ========================================================================
    {"EVU_SPERRE_AKTIV", FREQ_1MIN, cm_manager}, // Works
    // {"WP_EVU", FREQ_1MIN, cm_manager},
    //{"ABTAUUNGAKTIV", FREQ_1MIN, cm_heizmodul},
    {"BETRIEBSART_WP", FREQ_1MIN, cm_manager}, // Works
    {"PROGRAMMSCHALTER", FREQ_10MIN, cm_manager}, // Works - Tagesbetrieb, ...
    {"SOMMERBETRIEB", FREQ_10MIN, cm_manager}, // Works

    // ========================================================================
    // TEMPERATURE SIGNALS (30 SECOND INTERVAL)
    // cm_other = request from all available CAN members
    // ========================================================================
    // {"KESSELSOLLTEMP", FREQ_1MIN, cm_manager}, // Borked
    // {"KESSELSOLLTEMP", FREQ_1MIN, cm_kessel},
    // {"SPEICHERSOLLTEMP", FREQ_1MIN, cm_manager}, // Not on manager (WPC 7)
    {"SPEICHERSOLLTEMP", FREQ_10MIN, cm_kessel}, // Works
    // {"VORLAUFSOLLTEMP", FREQ_30S, cm_other},
    {"RAUMSOLLTEMP_I", FREQ_10MIN, cm_manager}, // Works
    {"RAUMSOLLTEMP_II", FREQ_10MIN, cm_manager}, // Works
    {"RAUMSOLLTEMP_III", FREQ_10MIN, cm_manager}, // Works
    {"RAUMSOLLTEMP_NACHT", FREQ_10MIN, cm_manager}, // Works
    {"AUSSENTEMP", FREQ_30S, cm_kessel}, // Works
    // {"AUSSENTEMP", FREQ_30S, cm_heizmodul},
    // {"SAMMLERISTTEMP", FREQ_30S, cm_kessel},
    {"SPEICHERISTTEMP", FREQ_30S, cm_kessel}, // Works
    // {"RAUMISTTEMP", FREQ_30S, cm_other},
    // {"VERSTELLTE_RAUMSOLLTEMP", FREQ_30S, cm_other},
    {"EINSTELL_SPEICHERSOLLTEMP", FREQ_10MIN, cm_kessel}, // Works
    {"EINSTELL_SPEICHERSOLLTEMP", FREQ_10MIN, cm_manager}, // Works
    {"EINSTELL_SPEICHERSOLLTEMP2", FREQ_10MIN, cm_kessel}, // Works
    {"EINSTELL_SPEICHERSOLLTEMP2", FREQ_10MIN, cm_manager}, // Works
    // {"VERDAMPFERTEMP", FREQ_30S, cm_kessel},
    // {"SAMMLERSOLLTEMP", FREQ_30S, cm_other},
    // {"RUECKLAUFISTTEMP", FREQ_30S, cm_manager},
    // {"VORLAUFISTTEMP", FREQ_30S, cm_kessel}, // Broken
    {"RUECKLAUFISTTEMP", FREQ_30S, cm_kessel}, // Works
    // {"SPEICHER_UNTEN_TEMP", FREQ_30S, cm_other},
    // {"SOLARZONENTEMP", FREQ_30S, cm_other},
    // {"SPEICHER_OBEN_TEMP", FREQ_30S, cm_other},
    // {"KOLLEKTORTEMP", FREQ_30S, cm_other},
    // {"FESTSTOFFKESSELTEMP", FREQ_30S, cm_other},
    // {"MIN_TEMP_KESSEL", FREQ_30S, cm_other},
    // {"ANFAHRTEMP", FREQ_30S, cm_other},
    // {"MAX_TEMP_KESSEL", FREQ_30S, cm_other},
    // {"MAX_TEMP_HZK", FREQ_30S, cm_other},
    // {"KOLLEKTORTEMP_2", FREQ_30S, cm_other},
    // {"MULTIFUNKTION_ISTTEMP", FREQ_30S, cm_other},
    // {"PUFFERTEMP_OBEN1", FREQ_30S, cm_other},
    // {"PUFFERTEMP_MITTE1", FREQ_30S, cm_other},
    // {"PUFFERTEMP_UNTEN1", FREQ_30S, cm_other},
    // {"PUFFERTEMP_OBEN2", FREQ_30S, cm_other},
    // {"PUFFERTEMP_MITTE2", FREQ_30S, cm_other},
    // {"PUFFERTEMP_UNTEN2", FREQ_30S, cm_other},
    // {"PUFFERTEMP_OBEN3", FREQ_30S, cm_other},
    // {"PUFFERTEMP_MITTE3", FREQ_30S, cm_other},
    // {"PUFFERTEMP_UNTEN3", FREQ_30S, cm_other},
    // {"AUSSENTEMPVERZOEGERUNG", FREQ_30S, cm_other},
    // {"AUSWAHL_STANDARDTEMP", FREQ_30S, cm_other},
    // {"MIN_TEMP_HZK", FREQ_30S, cm_other},
    // {"FERIEN_ABSENKTEMP", FREQ_30S, cm_other},
    // {"WW_MAXTEMP", FREQ_30S, cm_other},
    // {"KESSELSOLLTEMP_2WE", FREQ_30S, cm_other},
    // {"ABWESENHEITSTEMP", FREQ_30S, cm_other},
    // {"EINSTELL_SPEICHERSOLLTEMP3", FREQ_30S, cm_other},
    // {"ABGASTEMP", FREQ_30S, cm_other},
    // {"WW_SCHNELL_START_TEMPERATUR", FREQ_30S, cm_other},
    // {"MAX_WW_TEMP", FREQ_30S, cm_other},
    // {"BIVALENTPARALLELTEMPERATUR_HZG", FREQ_30S, cm_other},
    // {"BIVALENTPARALLELTEMPERATUR_WW", FREQ_30S, cm_other},
    // {"BIVALENZALTERNATIVTEMPERATUR_HZG", FREQ_30S, cm_other},
    // {"BIVALENZALTERNATIVTEMPERATUR_WW", FREQ_30S, cm_other},
    // {"QUELLENSOLLTEMPERATUR", FREQ_30S, cm_other},
    // {"AUSSENTEMPERATUR_WARMWASSER", FREQ_30S, cm_other},
    // {"SOLARTEMP_MAX", FREQ_30S, cm_other},
    // {"ESTRICH_SOCKELTEMPERATUR", FREQ_30S, cm_other},
    // {"ESTRICH_MAX_TEMPERATUR", FREQ_30S, cm_other},
    // {"SW_AUSSENTEMP", FREQ_30S, cm_other},
    // {"MAX_HEIZUNG_TEMP", FREQ_30S, cm_other},
    // {"TAUPUNKT_TEMP", FREQ_30S, cm_other},
    // {"HEISSGAS_TEMP", FREQ_30S, cm_other},
    {"WPVORLAUFIST", FREQ_30S, cm_kessel}, // Works
    {"QUELLE_IST", FREQ_30S, cm_kessel}, // Works
    {"QUELLENSOLLTEMPERATUR", FREQ_10MIN, cm_manager}, // Works
    {"HEISSGAS_TEMP", FREQ_30S, cm_kessel}, // Works
    // {"VERDICHTER", FREQ_30S, cm_kessel}, // Borked -> Test with cm_other
    {"WP_PUMPENSTATUS", FREQ_30S, cm_kessel}, // Works
    {"WW_ECO", FREQ_10MIN, cm_manager}, // Works
    {"ZWEITER_WE_STATUS", FREQ_1MIN, cm_manager}, // Unsure - Heizstab?
    {"ANTILEGIONELLEN", FREQ_10MIN, cm_manager}, // Works

    // ========================================================================
    // ENERGY COUNTERS (10 MINUTE INTERVAL)
    // Required for COP (Coefficient of Performance) calculations
    // ========================================================================
    // {"EL_AUFNAHMELEISTUNG_HEIZ_TAG_KWH", FREQ_10MIN, cm_manager},
    // {"EL_AUFNAHMELEISTUNG_HEIZ_SUM_MWH", FREQ_10MIN, cm_manager},
    // {"EL_AUFNAHMELEISTUNG_WW_TAG_KWH", FREQ_10MIN, cm_manager},
    // {"EL_AUFNAHMELEISTUNG_WW_SUM_MWH", FREQ_10MIN, cm_manager},
    // {"WAERMEERTRAG_2WE_WW_TAG_KWH", FREQ_10MIN, cm_manager},
    // {"WAERMEERTRAG_2WE_WW_SUM_MWH", FREQ_10MIN, cm_manager},
    // {"WAERMEERTRAG_2WE_HEIZ_TAG_KWH", FREQ_10MIN, cm_manager},
    // {"WAERMEERTRAG_2WE_HEIZ_SUM_MWH", FREQ_10MIN, cm_manager},
    // {"WAERMEERTRAG_WW_TAG_KWH", FREQ_10MIN, cm_manager},
    // {"WAERMEERTRAG_WW_SUM_MWH", FREQ_10MIN, cm_manager},
    // {"WAERMEERTRAG_HEIZ_TAG_KWH", FREQ_10MIN, cm_manager},
    // {"WAERMEERTRAG_HEIZ_SUM_MWH", FREQ_10MIN, cm_manager},

    // ========================================================================
    // RUNTIME COUNTERS (COMMENTED OUT - ENABLE IF NEEDED)
    // ========================================================================
    // {"LZ_VERD_1_2_HEIZBETRIEB", FREQ_10MIN, cm_manager},
    // {"LZ_VERD_1_2_WW_BETRIEB", FREQ_10MIN, cm_manager},
    // {"LZ_VERD_1_HEIZBETRIEB", FREQ_10MIN, cm_manager},
    // {"LZ_VERD_1_WW_BETRIEB", FREQ_10MIN, cm_manager},

    // ========================================================================
    // DEVICE INFORMATION (60 MINUTE INTERVAL)
    // ========================================================================
    //{"SOFTWARE_NUMMER", FREQ_60MIN, cm_other},
    //{"SOFTWARE_VERSION", FREQ_60MIN, cm_other},
    //{"GERAETE_ID", FREQ_60MIN, cm_other}
};

// Number of signals in the request table
#define SIGNAL_REQUEST_COUNT (sizeof(signalRequests) / sizeof(SignalRequest))

#endif // SIGNAL_REQUESTS_WPL13E_H
